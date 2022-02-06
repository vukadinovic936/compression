#include "Help.h"
Help::Help(){

}
Help::Help(std::string name, std::string description) : Command(name, description){

}
Help::~Help(){

}
int Help::run(){
	std::cout << STRINGS_HELP_CONTENT << std::endl;
	return 0;
}