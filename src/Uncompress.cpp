#include "Uncompress.h"
Uncompress::Uncompress(){

}
Uncompress::Uncompress(std::string name, std::string description) : Command(name, description){

}
Uncompress::~Uncompress(){

}
int Uncompress::run(std::string file_name){
	printf("Uncompressing...\n");
	std::string output_file = split(file_name, '.')[0]+"_decoded.txt";
//	std::string txt = read_file(filepath);
//	if(txt[txt.length()-1]=='0'){
//		write_file(STRINGS_CODING_FILE, STRINGS_HUFFMAN_CODING);	
//	}else{
//		write_file(STRINGS_CODING_FILE, STRINGS_ARITHMETIC);
//	}
//	txt=txt.substr(0,txt.length()-1);
//	write_file(filepath, txt);	
	CodingFactory fac;
	fac.getCoding()->uncompress(file_name, output_file);
	printf("File is uncompressed and saved as %s\n", output_file.c_str());
	return 0;
}
