#include "File.h"
#include <string>

File::File(){
	this->name = "";
	this->description = "";
}
File::~File(){

}
std::string File::getName(){
	return "bye";
}
std::string File::getDescription(){
	return "";
}
