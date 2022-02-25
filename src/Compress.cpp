#include "Compress.h"

Compress::Compress(): Command(){

}
Compress::Compress(std::string name, std::string description): Command(name,description){

}
Compress::~Compress(){

}
int Compress::run(){
	std::string filepath = "test.txt";
	std::string txt = read_file(filepath);
	CodingFactory fac;
	std::pair<std::string,code> res = fac.getCoding()->compress(txt);
	std::string compressed_string=res.first;
	code coding = res.second;
	std::cout << "COMPRESSED STRING IS" << std::endl;
	std::cout << compressed_string << std::endl;

	std::string uncompressed_string = fac.getCoding()->uncompress(compressed_string, coding);
	std::cout << std::endl;
	std::cout << "Uncompressed string is" << std::endl;
	std::cout << uncompressed_string << std::endl;
	return 0;
}
