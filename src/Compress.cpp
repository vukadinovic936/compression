#include "Compress.h"
using namespace std;
Compress::Compress(): Command(){

}
Compress::Compress(std::string name, std::string description): Command(name,description){

}
Compress::~Compress(){

}
int Compress::run(std::string file_name){
	//input params
	std::string output_file = split(file_name, '.')[0]+".zen";
	CodingFactory fac;
	fac.getCoding()->compress(file_name, output_file);

//	if(read_file(STRINGS_CODING_FILE)==STRINGS_HUFFMAN_CODING){
//		append_to_file(output_file, "0");	
//	}else{
//		append_to_file(output_file, "1");	
//	}
	return 0;
}
