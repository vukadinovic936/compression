#include <string>
#include <iostream>
#include "CommandFactory.h"
#include "StringsId.h"
#include "Arithmetic.h"
#include "Huffman.h"
#include "BigFloat.h"

using namespace std;
using namespace Helpers;
int main(int argc, char** argv){
	try{
		std::string commandName = argv[1];
		CommandFactory fac(commandName);	
		fac.getCommand()->run();
	}catch(exception e){
		CommandFactory fac(STRINGS_HELP_COMMAND);	
		fac.getCommand()->run();
	}
	return 0;
}
