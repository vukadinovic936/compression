#include "CommandFactory.h"
#include <iostream>
#include <string>

CommandFactory::CommandFactory(std::string name){

}
CommandFactory::~CommandFactory(){

}

Command* CommandFactory::getCommand(){
	return this->command;
}