#include "Command.h"
#include <string>

Command::Command(){
	this->name = "";
	this->description = "";
}

Command::Command(std::string name, std::string description){
	this->name = name;
	this->description = description;
}
Command::~Command(){

}
std::string Command::getName(){
	return this->name;
}
std::string Command::getDescription(){
	return this->description;
}
