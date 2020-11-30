#include <unordered_map>
#include <vector>
#include <memory>
#include <cstdarg>
#include <assert.h>
#include <math.h>
#include "std.h"
#include "parser.h"
using namespace std;

void throw_exception(const std::string err, int nl);


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
	data->stdfuncs.insert({"print", stdprint});
	data->stdfuncs.insert({"pow", stdpow});
	data->stdfuncs.insert({"test", test});
}


void is_valid_call(vector<sp<IVar>> *args, int nb_params, ...) {
	if(args->size()!=nb_params) {
		throw_exception("bad number of arguments!", 0);
	}
	va_list va_params;
	va_start(va_params, nb_params);
	for(int i=0; i<nb_params; i++)
		(*args)[i] = cast_type(va_arg(va_params, int), (*args)[i]);
	va_end(va_params);
}


sp<IVar> stdprint(vector<sp<IVar>> params) {
	for(int i=0; i<params.size(); i++)
		cout << *params[i];
	cout << endl;
	return NULL;
}

sp<IVar> stdpow(vector<sp<IVar>> params) {
	is_valid_call(&params, 2, DOUBLE, DOUBLE);
	Var<double> t1 = *params[0];
	Var<double> t2 = *params[1];
	double res = pow(*(double*)t1.value, *(double*)t2.value);
	return make_shared<Var<double>>(res);
}

sp<IVar> test(vector<sp<IVar>> params) {
	is_valid_call(&params, 1, DOUBLE);
	double val = Var<double>::getValue(params[0]);
	return make_shared<Var<double>>(val * 2);
}