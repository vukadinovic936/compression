#include "Arithmetic.h"
using namespace std;

Arithmetic::Arithmetic(){
	
}
Arithmetic::~Arithmetic(){

}

void Arithmetic::compress(std::string input_path, std::string output_path){

	clear_file(STRINGS_TEMP_ZEN);
	system(("echo -n \"$(cat "+ input_path + ")\" | ./lib/ArithCodeTut/src/arith_simple -C").c_str());	

	if (rename(STRINGS_TEMP_ZEN, output_path.c_str()) != 0)
		perror("Error renaming file");
	else
		cout << "File renamed successfully";	
}

void Arithmetic::uncompress(std::string input_path, std::string output_path){

	clear_file(STRINGS_DECODED_TXT);
	system(("echo \"$(cat "+ input_path+ ")\" | ./lib/ArithCodeTut/src/arith_simple -D").c_str());

	if (rename(STRINGS_DECODED_TXT, output_path.c_str()) != 0)
		perror("Error renaming file");
	else
		cout << "File renamed successfully";
}