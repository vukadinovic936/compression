#include "Algos.h"
Algos::Algos(){

}
Algos::Algos(std::string name, std::string description):Command(name, description){

}
Algos::~Algos(){

}
int Algos::run(){
	std::cout << "comparing algos" << std::endl;
	return 0;
}