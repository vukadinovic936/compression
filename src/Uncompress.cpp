#include "Uncompress.h"
Uncompress::Uncompress(){

}
Uncompress::Uncompress(std::string name, std::string description) : Command(name, description){

}
Uncompress::~Uncompress(){

}
int Uncompress::run(){
	std::cout <<"Uncompressing" << std::endl;
	return 0;
}
