#include "Compress.h"

Compress::Compress(): Command(){

}
Compress::Compress(std::string name, std::string description): Command(name,description){

}
Compress::~Compress(){

}
int Compress::run(){
	std::cout << "Running Compression" << std::endl;
	return 0;
}
