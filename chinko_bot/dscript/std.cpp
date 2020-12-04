#include <unordered_map>
#include <vector>
#include <memory>
#include <cstdarg>
#include <fstream> 
#include <assert.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>
#include "std.h"
#include "parser.h"

using namespace std;


/*
	Pour ajouter une fonction std :
		- ajouter une ligne de la forme `stdfuncs.insert({nom_fonction_dans_le_script, fonction_effectivement_appelée});` dans initstd()
		- créer la fonction elle-même dans std.cpp (ainsi que son prototype dans std.h).
			-> la fonction doit être de type stdf (voir std.h) : elle prend en paramètre un vecteur de sp<IVar> et retourne un sp<IVar>
			-> voir stdprint et stdpow pour exemples
		- commencer la fonction par is_valid_call(&params, nombre_paramètres, type_paramètre1, type_paramètre2, etc);
		- retourner NULL si la fonction ne retourne rien, le sp<IVar> sinon.
*/


void initstd(parser_data_t *data) {
	data->stdfuncs = {};
	data->usrfuncs = {};
	/* Standards */
	data->stdfuncs.insert({"callscript", stdcallscript});
	data->stdfuncs.insert({"print", stdprint});
	data->stdfuncs.insert({"println", stdprintln});
	data->stdfuncs.insert({"time", stdtime});
	data->stdfuncs.insert({"millis", stdmillis});
	/* Types */
	data->stdfuncs.insert({"string", stdstring});
	data->stdfuncs.insert({"double", stddouble});
	data->stdfuncs.insert({"bool", stdbool});
	data->stdfuncs.insert({"char", stdchar});
	data->stdfuncs.insert({"int", stdint});
	/* Strings */
	data->stdfuncs.insert({"substr", stdsubstr});
	data->stdfuncs.insert({"find", stdfind});
	data->stdfuncs.insert({"getchar", stdgetchar});
	data->stdfuncs.insert({"strlen", stdstrlen});
	/* Math */
	data->stdfuncs.insert({"pow", stdpow});
	data->stdfuncs.insert({"abs", stdabs});
	data->stdfuncs.insert({"min", stdmin});
	data->stdfuncs.insert({"max", stdmax});
	data->stdfuncs.insert({"pi", stdpi});
	data->stdfuncs.insert({"exp", stdexp});
	data->stdfuncs.insert({"log", stdlog});
	data->stdfuncs.insert({"sqrt", stdsqrt});
	data->stdfuncs.insert({"round", stdround});
	data->stdfuncs.insert({"isinf", stdisinf});
	data->stdfuncs.insert({"isNaN", stdisNaN});
	data->stdfuncs.insert({"sin", stdsin});
	data->stdfuncs.insert({"cos", stdcos});
	data->stdfuncs.insert({"tan", stdtan});
	data->stdfuncs.insert({"asin", stdasin});
	data->stdfuncs.insert({"acos", stdacos});
	data->stdfuncs.insert({"atan", stdatan});
	data->stdfuncs.insert({"rand", stdrand});
	data->stdfuncs.insert({"randint", stdrandint});
	data->stdfuncs.insert({"throw", stdthrow});
	/* I/O Files&Input */
	data->stdfuncs.insert({"readfile", stdreadfile});
	data->stdfuncs.insert({"writefile", stdwritefile});
	data->stdfuncs.insert({"createfile", stdcreatefile});
	data->stdfuncs.insert({"input", stdinput});
}


void is_valid_call(vector<sp<IVar>> *args, int nline, int nb_params, ...) {
	if(args->size()!=nb_params)
		throw_exception("bad number of arguments!", nline);

	va_list va_params;
	va_start(va_params, nb_params);
	for(int i=0; i<nb_params; i++)
		(*args)[i] = cast_type(va_arg(va_params, int), (*args)[i], nline);
	va_end(va_params);
}


/* STANDARDS */

sp<IVar> stdcallscript(parser_data_t *data, vector<sp<IVar>> params, int nline) {
	is_valid_call(&params, nline, 1, STRING);
	string file = *(string*)params[0]->value;
	dscript(file, data->stop);
}

sp<IVar> stdprintln(parser_data_t *data, vector<sp<IVar>> params, int nline) {
	stdprint(data, params, nline);
	cout << endl;
	return NULL;
}

sp<IVar> stdprint(parser_data_t *data, vector<sp<IVar>> params, int nline) {
	for(int i=0; i<params.size(); i++)
		cout << *params[i];
	return NULL;
}

sp<IVar> stdthrow(parser_data_t *data, std::vector<sp<IVar>> params, int nline) {
	is_valid_call(&params, nline, 1, STRING);
	string msg = *(string*)params[0]->value;
	throw_exception(msg, nline);
}

sp<IVar> stdtime(parser_data_t *data, vector<sp<IVar>> params, int nline) {
	/* retourne le nombre de secondes depuis le 1er janvier 1970 00h00 */
	is_valid_call(&params, nline, 0);
	return make_shared<Var<uint32_t>>(time(NULL));
}

sp<IVar> stdmillis(parser_data_t *data, vector<sp<IVar>> params, int nline) {
	/* retourne un nombre de millisecondes donnée par la fonction gettimeofday */
	is_valid_call(&params, nline, 0);
	struct timeval now;
	gettimeofday(&now, NULL);
	return make_shared<Var<uint32_t>>(now.tv_usec/1000+now.tv_sec*1000);
}


/* TYPES */

sp<IVar> stdstring(parser_data_t *data, std::vector<sp<IVar>> params, int nline) {
	if(params.size()!=1)
		throw_exception("bad number of arguments!", nline);
	switch(params[0]->get_type()) {
		case INT32:
		case UINT32:
		case INT8:
		case UINT8:
			return make_shared<Var<string>>(to_string(*(int*)params[0]->value));
		case BOOL:
			return make_shared<Var<string>>(*(bool*)params[0]->value ? "true" : "false");
		case CHAR:
			return make_shared<Var<string>>(string(1, *(char*)params[0]->value));
		case DOUBLE:
			return make_shared<Var<string>>(to_string(*(double*)params[0]->value));
		case STRING:
			return params[0];
		default:
			throw_exception("error invalid argument type", nline);
	}
	return NULL;
}

sp<IVar> stddouble(parser_data_t *data, vector<sp<IVar>> params, int nline) {
	if(params.size()!=1)
		throw_exception("bad number of arguments!", nline);
	switch(params[0]->get_type()) {
		case INT32:
		case UINT32:
		case INT8:
		case UINT8:
		case BOOL:
		case CHAR:
		case DOUBLE:
			return cast_type(DOUBLE, params[0], nline);
		case STRING:
			return make_shared<Var<double>>(atof(((string*)params[0]->value)->c_str()));
		default:
			throw_exception("error invalid argument type", nline);
	}
	return NULL;
}

sp<IVar> stdbool(parser_data_t *data, vector<sp<IVar>> params, int nline) {
	if(params.size()!=1)
		throw_exception("bad number of arguments!", nline);
	switch(params[0]->get_type()) {
		case INT32:
		case UINT32:
		case INT8:
		case UINT8:
		case CHAR:
		case BOOL:
		case DOUBLE:
			return cast_type(BOOL, params[0], nline);
		case STRING:
			if(*(string*)params[0]->value=="true")
				return make_shared<Var<bool>>(true);
			else if(*(string*)params[0]->value=="false")
				return make_shared<Var<bool>>(false);
			throw_exception("invalid conversion from string to boolean", nline);
		default:
			throw_exception("invalid argument type", nline);
	}
	return NULL;
}

sp<IVar> stdchar(parser_data_t *data, std::vector<sp<IVar>> params, int nline) {
	is_valid_call(&params, nline, 1, CHAR);
	return params[0];
}

sp<IVar> stdint(parser_data_t *data, std::vector<sp<IVar>> params, int nline) {
	if(params.size()!=1)
		throw_exception("bad number of arguments!", nline);
	switch(params[0]->get_type()) {
		case INT32:
		case UINT32:
		case INT8:
		case UINT8:
		case CHAR:
		case DOUBLE:
		case BOOL:
			return cast_type(INT32, params[0], nline);
		case STRING:
			return make_shared<Var<int32_t>>(atoi(((string*)params[0]->value)->c_str()));
		default:
			throw_exception("invalid argument type", nline);
	}
	return NULL;
}


/* STRINGS */

sp<IVar> stdsubstr(parser_data_t *data, std::vector<sp<IVar>> params, int nline) {
	is_valid_call(&params, nline, 3, STRING, UINT32, UINT32); // substr("My string", 3, 2); -> "st"
	string str = *(string*)params[0]->value;
	uint32_t pos = *(uint32_t*)params[1]->value;
	uint32_t len = *(uint32_t*)params[2]->value;
	return make_shared<Var<string>>(str.substr(pos, len));
}

sp<IVar> stdfind(parser_data_t *data, std::vector<sp<IVar>> params, int nline) {
	is_valid_call(&params, nline, 2, STRING, STRING);
	string src = *(string*)params[0]->value;
	string fnd = *(string*)params[1]->value;
	return make_shared<Var<int32_t>>(src.find(fnd));
}

sp<IVar> stdgetchar(parser_data_t *data, std::vector<sp<IVar>> params, int nline) {
	is_valid_call(&params, nline, 2, STRING, INT32);
	string str = *(string*)params[0]->value;
	int32_t pos = *(int32_t*)params[1]->value + str.length();
	if(pos > str.length()*2-1)
		throw_exception("out of range", nline);
	pos %= str.length();
	return make_shared<Var<char>>(str.at(pos));
}

sp<IVar> stdstrlen(parser_data_t *data, std::vector<sp<IVar>> params, int nline) {
	is_valid_call(&params, nline, 1, STRING);
	string str = *(string*)params[0]->value;
	return make_shared<Var<uint32_t>>(str.length());
}


/* MATH */

sp<IVar> stdpow(parser_data_t *data, vector<sp<IVar>> params, int nline) {
	is_valid_call(&params, nline, 2, DOUBLE, DOUBLE);
	Var<double> t1 = *params[0];
	Var<double> t2 = *params[1];
	double res = pow(*(double*)t1.value, *(double*)t2.value);
	return make_shared<Var<double>>(res);
}

sp<IVar> stdabs(parser_data_t *data, std::vector<sp<IVar>> params, int nline) {
	if(params.size()!=1)
		throw_exception("bad number of arguments!", nline);
	if(params[0]->get_type()==STRING || params[0]->get_type()==CHAR || params[0]->get_type()==BOOL)
		throw_exception("invalid argument type", nline);
	const sp<IVar> ZERO = make_shared<Var<int32_t>>(0);
	return *params[0] > *ZERO ? params[0] : *ZERO - *params[0];
}

sp<IVar> stdmin(parser_data_t *data, std::vector<sp<IVar>> params, int nline) {
	if(params.size()==0)
		throw_exception("bad number of arguments!", nline);
	sp<IVar> min = NULL;
	const sp<IVar> ZERO = make_shared<Var<int32_t>>(0);
	for(int i=0; i<params.size(); i++) {
		if(params[i]->get_type()==STRING)
			throw_exception("invalid argument type", nline);
		if(min==NULL || *(*min - *params[i]) > *ZERO)
			min = params[i];
	}
	return min;
}

sp<IVar> stdmax(parser_data_t *data, std::vector<sp<IVar>> params, int nline) {
	if(params.size()==0)
		throw_exception("bad number of arguments!", nline);
	sp<IVar> min = NULL;
	const sp<IVar> ZERO = make_shared<Var<int32_t>>(0);
	for(int i=0; i<params.size(); i++) {
		if(params[i]->get_type()==STRING)
			throw_exception("invalid argument type", nline);
		if(min==NULL || *(*min - *params[i]) < *ZERO)
			min = params[i];
	}
	return min;
}

sp<IVar> stdpi(parser_data_t *data, std::vector<sp<IVar>> params, int nline) {
	is_valid_call(&params, nline, 0);
	return make_shared<Var<double>>(M_PI);
}

sp<IVar> stdexp(parser_data_t *data, std::vector<sp<IVar>> params, int nline) {
	is_valid_call(&params, nline, 1, DOUBLE);
	double n = *(double*)params[0]->value;
	return make_shared<Var<double>>(exp(n));
}

sp<IVar> stdlog(parser_data_t *data, std::vector<sp<IVar>> params, int nline) {
	if(params.size()==1) {
		is_valid_call(&params, nline, 1, DOUBLE);
		double n = *(double*)params[0]->value;
		return make_shared<Var<double>>(log(n));
	} else {
		is_valid_call(&params, nline, 2, DOUBLE, UINT32);
		double n = *(double*)params[0]->value;
		uint32_t base = *(uint32_t*)params[1]->value;
		return make_shared<Var<double>>(log(n)/log(base));
	}
}

sp<IVar> stdsqrt(parser_data_t *data, std::vector<sp<IVar>> params, int nline) {
	is_valid_call(&params, nline, 1, DOUBLE);
	double n = *(double*)params[0]->value;
	return make_shared<Var<double>>(sqrt(n));
}

sp<IVar> stdround(parser_data_t *data, std::vector<sp<IVar>> params, int nline) {
	if(params.size()==1) {
		is_valid_call(&params, nline, 1, DOUBLE);
		double n = *(double*)params[0]->value;
		return make_shared<Var<double>>(round(n));
	} else {
		is_valid_call(&params, nline, 2, DOUBLE, UINT32);
		double n = *(double*)params[0]->value;
		const uint32_t exp = *(uint32_t*)params[1]->value;
		n = n*pow(10, exp);
		n = round(n);
		n = n/pow(10, exp);
		return make_shared<Var<double>>(n);
	}
}

sp<IVar> stdisinf(parser_data_t *data, std::vector<sp<IVar>> params, int nline) {
	is_valid_call(&params, nline, 1, DOUBLE);
	double n = *(double*)params[0]->value;
	return make_shared<Var<double>>(isinf(n));
}

sp<IVar> stdisNaN(parser_data_t *data, std::vector<sp<IVar>> params, int nline) {
	is_valid_call(&params, nline, 1, DOUBLE);
	double n = *(double*)params[0]->value;
	return make_shared<Var<double>>(isnan(n));
}

sp<IVar> stdsin(parser_data_t *data, std::vector<sp<IVar>> params, int nline) {
	is_valid_call(&params, nline, 1, DOUBLE);
	double n = *(double*)params[0]->value;
	return make_shared<Var<double>>(sin(n));
}

sp<IVar> stdcos(parser_data_t *data, std::vector<sp<IVar>> params, int nline) {
	is_valid_call(&params, nline, 1, DOUBLE);
	double n = *(double*)params[0]->value;
	return make_shared<Var<double>>(cos(n));
}

sp<IVar> stdtan(parser_data_t *data, std::vector<sp<IVar>> params, int nline) {
	is_valid_call(&params, nline, 1, DOUBLE);
	double n = *(double*)params[0]->value;
	return make_shared<Var<double>>(tan(n));
}

sp<IVar> stdasin(parser_data_t *data, std::vector<sp<IVar>> params, int nline) {
	is_valid_call(&params, nline, 1, DOUBLE);
	double n = *(double*)params[0]->value;
	return make_shared<Var<double>>(asin(n));
}

sp<IVar> stdacos(parser_data_t *data, std::vector<sp<IVar>> params, int nline) {
	is_valid_call(&params, nline, 1, DOUBLE);
	double n = *(double*)params[0]->value;
	return make_shared<Var<double>>(acos(n));
}

sp<IVar> stdatan(parser_data_t *data, std::vector<sp<IVar>> params, int nline) {
	is_valid_call(&params, nline, 1, DOUBLE);
	double n = *(double*)params[0]->value;
	return make_shared<Var<double>>(atan(n));
}

sp<IVar> stdrand(parser_data_t *data, std::vector<sp<IVar>> params, int nline) {
	is_valid_call(&params, nline, 0);
	srand(time(NULL));
	return make_shared<Var<double>>((double)rand()/RAND_MAX);
}

sp<IVar> stdrandint(parser_data_t *data, std::vector<sp<IVar>> params, int nline) {
	is_valid_call(&params, nline, 2, INT32, INT32);
	uint32_t a = *(uint32_t*)params[0]->value;
	uint32_t b = *(uint32_t*)params[1]->value;
	srand(time(NULL));
	return make_shared<Var<double>>(a+rand()%(b-a));
}


/* I/O FILES&INPUT */

sp<IVar> stdreadfile(parser_data_t *data, std::vector<sp<IVar>> params, int nline) {
	is_valid_call(&params, nline, 1, STRING);
	string file = *(string*)params[0]->value;

	FILE *fp = fopen(file.c_str(), "r");
	if(fp==NULL)
		throw_exception(file+" not found!", nline);
	fseek(fp, 0L, SEEK_END);
	size_t size = ftell(fp);
	rewind(fp);
	char content[size+1];
	fread(content, 1, size, fp);
	content[size] = 0x0;
	fclose(fp);

	return make_shared<Var<string>>(string(content));
}

sp<IVar> stdwritefile(parser_data_t *data, std::vector<sp<IVar>> params, int nline) {
	// si le fichier n'existe pas, le crée
	is_valid_call(&params, nline, 2, STRING, STRING);
	string file = *(string*)params[0]->value;
	const char *content = ((string*)params[1]->value)->c_str();

	FILE *fp = fopen(file.c_str(), "w");
	if(fp==NULL)
		throw_exception("an error occurred", nline);
	fwrite(content, strlen(content), 1, fp);
	fclose(fp);

	return NULL;
}

sp<IVar> stdcreatefile(parser_data_t *data, std::vector<sp<IVar>> params, int nline) {
	// si un fichier a déjà ce nom, ne fait rien
	is_valid_call(&params, nline, 1, STRING);
	string file = *(string*)params[0]->value;
	ofstream outfile(file);
	outfile.close();
	return NULL;
}

sp<IVar> stdinput(parser_data_t *data, std::vector<sp<IVar>> params, int nline) {
	is_valid_call(&params, nline, 0);
	string input;
	getline(cin, input);
	return make_shared<Var<string>>(input);
}

