#include <unordered_map>
#include <vector>
#include <memory>
#include <cstdarg>
#include <assert.h>
#include <math.h>
#include "std.h"
#include "parser.h"
#include <unistd.h>

#include "ScriptThread.h"

#include "LogBotCommand.h"
#include "ChangeToUpMapBotCommand.h"
#include "ChangeToDownMapBotCommand.h"
#include "ChangeToLeftMapBotCommand.h"
#include "ChangeToRightMapBotCommand.h"

#include "CollectInteractivesBotCommand.h"

#include "BotCommandReturnValues.h"
#include "NoReturnValue.h"
#include "WrongCommand.h"
#include "CommandSuccessReturnValue.h"

#include "RequestWeightBotCommand.h"
#include "WeightReturnValues.h"

using namespace std;

unordered_map<string, stdf> stdfuncs;

ScriptConfig config;
ScriptState currentScriptState = no_script;
sp<BotCommand> currentCommand = nullptr;
sp<BotCommandReturnValues> currentReturnValues = nullptr;

int currentCommandNumber = 0;

#define CHECK_RETURN_TYPE(ret, type, cmd_name) if(!dynamic_pointer_cast<type>(ret)) throw ("Command " cmd_name " did not have '"  #type "' as return values");
#define CHECK_RETURN_TYPE_AND_CAST(ret, dest_cast, type, cmd_name) sp<type> dest_cast = dynamic_pointer_cast<type>(ret); if(!dest_cast) throw ("Command " cmd_name " did not have '"  #type "' as return values");

/*
	Pour lancer les commandes et avoir l'état qu'il faut : 
	- variables globale pour
		. la commande et sa valeur de retour
		. "l'état" de l'interpréteur : running, 'cmd_asking', cmd_waiting, cmd_stop
	- si running, l'interpréteur -doit- être entrain d'éxecuter le script. Débloque l'interpréteur si il attendait une réponse à une commande
	- si 'cmd_asking', l'interpréteur viens de lancer une commande qui n'a pas encore été prise en charge
	- si cmd_waiting, la dernière commande a été prise en charge par le commandManager et l'interpréteur attend une réponse à sa commande 
	- si cmd_stop, la commande d'arret du script a été lancée, l'interpréteur doit se débloquer si il attendait une réponse à une commande
	- tous ces états sont set par la commandThread (dirigé par le commandManager) sauf l'état 'cmd_asking'
*/


/*
	Pour ajouter une fonction std :
		- ajouter une ligne de la forme `stdfuncs.insert({nom_fonction_dans_le_script, fonction_effectivement_appelée});` dans initstd()
		- créer la fonction elle-même dans std.cpp (ainsi que son prototype dans std.h).
			-> la fonction doit être de type stdf (voir std.h) : elle prend en paramètre un vecteur de sp<IVar> et retourne un sp<IVar>
			-> voir stdprint et stdpow pour exemples
		- commencer la fonction par is_valid_call(&params, nombre_paramètres, type_paramètre1, type_paramètre2, etc);
		- retourner NULL si la fonction ne retourne rien, le sp<IVar> sinon.
*/

sp<BotCommandReturnValues> launchCommand(sp<BotCommand> command) {
	// TODO ? : mettre le nom de la fonction dans les erreurs ?
	if(currentScriptState != running)
		throw "Tried to launch a command while the script was no running";

	command->commandNumber = currentCommandNumber;
	
	currentCommand = command;
	currentReturnValues = nullptr;
	currentScriptState = launching_cmd;

	while(currentScriptState != running)
		usleep(1);

	if(!currentReturnValues)
		throw "Command launch did not set any commandReturnValues";

	if(currentReturnValues->commmandNumber != command->commandNumber)
		throw "Command's return values' command number do not match launched command number";

	if(dynamic_pointer_cast<WrongCommand>(currentReturnValues))
		throw "Tried to launch a wrong command, received a 'WrongCommand' as retrun value. Full command must not have been implemented yet.";

	currentCommandNumber++;

	currentCommand = nullptr;
	return currentReturnValues;
}

void initstd() {
	stdfuncs = {};
	stdfuncs.insert({"pow", stdpow});
	stdfuncs.insert({"log", stdlog});
	stdfuncs.insert({"usleep", usleep});
	stdfuncs.insert({"randRange", randRange});

	stdfuncs.insert({"mapUp", mapUp});
	stdfuncs.insert({"mapDown", mapDown});
	stdfuncs.insert({"mapLeft", mapLeft});
	stdfuncs.insert({"mapRight", mapRight});

	stdfuncs.insert({"collect", collectInteractives});

	stdfuncs.insert({"isFull", isFull});
	stdfuncs.insert({"getWeightStatusAsString", weightStatusAsString});
}

void is_valid_call(vector<sp<IVar>> *args, int nb_params, ...) {
	if(args->size()!=nb_params) {
		// TODO ? : mettre le nom de la fonction dans l'erreur ?
		throw "Nombre d'arguments spécifiés incorrect (attendus : " + to_string(nb_params) + "; obtenus : " + to_string(args->size()) + ").";
	}

	va_list va_params;
	va_start(va_params, nb_params);
	for(int i=0; i<nb_params; i++)
		(*args)[i] = cast_type(va_arg(va_params, int), (*args)[i]);
	va_end(va_params);
}


sp<IVar> stdlog(vector<sp<IVar>> params) {
	string log = "";

	for(int i=0; i<params.size(); i++)
		log += params[i]->asString();

	sp<BotCommandReturnValues> ret = launchCommand(make_shared<LogBotCommand>(log));
	CHECK_RETURN_TYPE(ret, NoReturnValue, "log")

	return nullptr;
}

sp<IVar> stdpow(vector<sp<IVar>> params) {
	is_valid_call(&params, 2, DOUBLE, DOUBLE);
	Var<double> t1 = *params[0];
	Var<double> t2 = *params[1];
	double res = pow(*(double*)t1.value, *(double*)t2.value);
	return make_shared<Var<double>>(res);
}

sp<IVar> mapUp(vector<sp<IVar>> params) {
	is_valid_call(&params, 1, INT32);
	cout << "up" << endl;

	int floor = Var<int32_t>::getValue(params[0]);

	sp<BotCommandReturnValues> ret = launchCommand(make_shared<ChangeToUpMapBotCommand>(floor));
	CHECK_RETURN_TYPE_AND_CAST(ret, csRVal, CommandSuccessReturnValue, "mapUp")
	if(!csRVal->success) {
		Logger::write("Command mapUp was not successful. IL FAUDRAIT STOPPER LE SCRIPT A CE MOMENT LA", LOG_ERROR);
	}

	return nullptr;
}

sp<IVar> mapDown(vector<sp<IVar>> params) {
	is_valid_call(&params, 1, INT32);
	cout << "down" << endl;

	int floor = Var<int32_t>::getValue(params[0]);

	sp<BotCommandReturnValues> ret = launchCommand(make_shared<ChangeToDownMapBotCommand>(floor));
	CHECK_RETURN_TYPE_AND_CAST(ret, csRVal, CommandSuccessReturnValue, "mapDown")
	if(!csRVal->success) {
		Logger::write("Command mapDown was not successful. IL FAUDRAIT STOPPER LE SCRIPT A CE MOMENT LA", LOG_ERROR);
	}

	return nullptr;
}

sp<IVar> mapLeft(vector<sp<IVar>> params) {
	is_valid_call(&params, 1, INT32);
	cout << "left" << endl;

	int floor = Var<int32_t>::getValue(params[0]);

	sp<BotCommandReturnValues> ret = launchCommand(make_shared<ChangeToLeftMapBotCommand>(floor));
	CHECK_RETURN_TYPE_AND_CAST(ret, csRVal, CommandSuccessReturnValue, "mapLeft")
	if(!csRVal->success) {
		Logger::write("Command mapLeft was not successful. IL FAUDRAIT STOPPER LE SCRIPT A CE MOMENT LA", LOG_ERROR);
	}

	return nullptr;
}

sp<IVar> mapRight(vector<sp<IVar>> params) {
	is_valid_call(&params, 1, INT32);
	cout << "right" << endl;

	int floor = Var<int32_t>::getValue(params[0]);

	sp<BotCommandReturnValues> ret = launchCommand(make_shared<ChangeToRightMapBotCommand>(floor));
	CHECK_RETURN_TYPE_AND_CAST(ret, csRVal, CommandSuccessReturnValue, "mapRight")
	if(!csRVal->success) {
		Logger::write("Command mapRight was not successful. IL FAUDRAIT STOPPER LE SCRIPT A CE MOMENT LA", LOG_ERROR);
	}

	return nullptr;
}

sp<IVar> usleep(vector<sp<IVar>> params) {
	is_valid_call(&params, 1, INT32);

	int32_t t = Var<int32_t>::getValue(params[0]);  
	usleep(t);

	return nullptr;
}

sp<IVar> collectInteractives(vector<sp<IVar>> params) {
	is_valid_call(&params, 0);
	cout << "collect" << endl;

	vector<int> interactives;
	for(int i : config.interactives_to_collect)
		interactives.push_back(i);

	sp<BotCommandReturnValues> ret = launchCommand(make_shared<CollectInteractivesBotCommand>(interactives));
	CHECK_RETURN_TYPE_AND_CAST(ret, csRVal, CommandSuccessReturnValue, "mapRight")
	if(!csRVal->success) {
		Logger::write("Command mapRight was not successful. IL FAUDRAIT STOPPER LE SCRIPT A CE MOMENT LA", LOG_ERROR);
	}

	return nullptr;
}

sp<IVar> isFull(vector<sp<IVar>> params) {
	is_valid_call(&params, 0);
	cout << "isFull" << endl;

	sp<BotCommandReturnValues> ret = launchCommand(make_shared<RequestWeightBotCommand>());
	CHECK_RETURN_TYPE_AND_CAST(ret, wrVal, WeightReturnValues, "mapRight")

	sp<IVar> isFullVar = make_shared<Var<bool>>(wrVal->weight >= wrVal->weightMax);
	return isFullVar;
}

sp<IVar> weightStatusAsString(vector<sp<IVar>> params) {
	is_valid_call(&params, 0);
	cout << "weightStatus" << endl;

	sp<BotCommandReturnValues> ret = launchCommand(make_shared<RequestWeightBotCommand>());
	CHECK_RETURN_TYPE_AND_CAST(ret, wrVal, WeightReturnValues, "mapRight")

	sp<IVar> weightStatus = make_shared<Var<string>>(to_string(wrVal->weight) + "/" + to_string(wrVal->weightMax));
	return weightStatus;
}

sp<IVar> randRange(vector<sp<IVar>> params) {
	is_valid_call(&params, 2, INT32, INT32);
	int i0 = Var<int>::getValue(params[0]);
	int i1 = Var<int>::getValue(params[1]);

	if(i1 <= i0)
		throw "Cannot make a randRange between " + to_string(i0) + " and " + to_string(i1) + ".";

	int ret = (rand() % (i1 - i0)) + i0;

	return make_shared<Var<int>>(ret);
}