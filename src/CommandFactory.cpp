#include "CommandFactory.h"

CommandFactory::CommandFactory(std::string name){

	if(name == STRINGS_COMPRESS_COMMAND){
		this->command = new Compress(name,"");
	}else if(name == STRINGS_UNCOMPRESS_COMMAND){
		this->command = new Uncompress(name,"");
	}else if (name == STRINGS_ALGOS_COMMAND){
		this->command = new Algos(name,"");
	}else{
		// Show Help
		this->command = new Help(name, "");
	}
}
CommandFactory::~CommandFactory(){

}

Command* CommandFactory::getCommand(){
	return this->command;
}