#include <iostream>
#include <unordered_map>
#include "parser.h"
#include "../../Var/Var.h"

using namespace std;

int main(void) {
	try {
		dscript("chinko_bot/dscript/dscript.txt");
	} catch(const exception& e) {
		cout << e.what() << endl;
	}

	cout << "ESSAYONS EN UN AUTRE..." << endl;

	try {
		dscript_cmd("print(42);\n\n");
	} catch(const exception& e) {
		cout << e.what() << endl;
	}
	return 0;
}