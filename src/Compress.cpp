#include "Compress.h"
using namespace std;
Compress::Compress(): Command(){

}
Compress::Compress(std::string name, std::string description): Command(name,description){

}
Compress::~Compress(){

}
int Compress::run(){
	//input params
	std::string filepath = "test/test3.txt";
	std::string output_file = "temp.zen";	

	std::string txt = read_file(filepath);
	CodingFactory fac;
	fac.getCoding()->compress(filepath, output_file);

//	if(read_file(STRINGS_CODING_FILE)==STRINGS_HUFFMAN_CODING){
//		append_to_file(output_file, "0");	
//	}else{
//		append_to_file(output_file, "1");	
//	}
	return 0;
}
