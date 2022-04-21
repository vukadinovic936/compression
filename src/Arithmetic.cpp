#include "Arithmetic.h"
using namespace std;

Arithmetic::Arithmetic(){
	
}
Arithmetic::~Arithmetic(){

}

void Arithmetic::compress(std::string input_path, std::string output_path){

	clear_file(STRINGS_TEMP_ZEN);
	system(("echo -n \"$(cat "+ input_path + ")\" | " + std::string(STRINGS_WORKING_DIR) + "/lib/ArithCodeTut/src/arith_simple -C").c_str());	

	if (rename(STRINGS_TEMP_ZEN, output_path.c_str()) != 0)
		perror("Error renaming file");
	
	exec( ("python3 " + std::string(STRINGS_WORKING_DIR) + "/lib/string_to_binary.py "+output_path).c_str());
}

void Arithmetic::uncompress(std::string input_path, std::string output_path){

	exec( ("python3 " + std::string(STRINGS_WORKING_DIR) + "/lib/binary_to_string.py "+input_path).c_str());

	clear_file(STRINGS_DECODED_TXT);
	system(("echo \"$(cat "+ input_path+ ")\" | "+ std::string(STRINGS_WORKING_DIR) +"/lib/ArithCodeTut/src/arith_simple -D").c_str());

	if (rename(STRINGS_DECODED_TXT, output_path.c_str()) != 0)
		perror("Error renaming file");
}