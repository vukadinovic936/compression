#include <string>
#include <iostream>
#include "CommandFactory.h"
#include "StringsId.h"
#include "Arithmetic.h"
#include "Huffman.h"
#include "BigFloat.h"
#include "Arithmetic.h"
#include <fstream>
using namespace std;
using namespace Helpers;

int main(int argc, char** argv){
	try{
		std::string commandName = argv[1];
		std::string file_name = "";
		if(argc > 2){
			file_name = argv[2];
		}
		CommandFactory fac(commandName);	
		fac.getCommand()->run(file_name);
	}catch(exception e){
		CommandFactory fac(STRINGS_HELP_COMMAND);	
		fac.getCommand()->run("");
	}
	return 0;
}
