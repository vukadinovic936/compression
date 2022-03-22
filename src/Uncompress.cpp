#include "Uncompress.h"
Uncompress::Uncompress(){

}
Uncompress::Uncompress(std::string name, std::string description) : Command(name, description){

}
Uncompress::~Uncompress(){

}
int Uncompress::run(){
	std::cout <<"Uncompressing" << std::endl;
	//input params
	std::string filepath = "temp.zen";
	std::string output_path = "decoded.txt";

//	std::string txt = read_file(filepath);
//	if(txt[txt.length()-1]=='0'){
//		write_file(STRINGS_CODING_FILE, STRINGS_HUFFMAN_CODING);	
//	}else{
//		write_file(STRINGS_CODING_FILE, STRINGS_ARITHMETIC);
//	}
//	txt=txt.substr(0,txt.length()-1);
//	write_file(filepath, txt);	
	CodingFactory fac;
	fac.getCoding()->uncompress(filepath, output_path);
	return 0;
}
