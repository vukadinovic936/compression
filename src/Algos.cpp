#include "Algos.h"
Algos::Algos(){

}

Algos::Algos(std::string name, std::string description):Command(name, description){

}

int Algos::run(std::string file_name){
	int user_input;
	if(!file_name.empty()){
		if(file_name=="HUFFMAN"){
			user_input=1;
		}else if (file_name=="ARITHMETIC"){
			user_input=2;
		}
	}else{
		printf("SELECT THE CODE YOU WANT TO USE\n");
		printf("1: HUFFMAN\n");
		printf("2: ARITHMETIC\n");
		scanf("%d",&user_input);
	}
	std::ofstream coding_file;
	coding_file.open(std::string(STRINGS_WORKING_DIR) + "/coding.txt" );
	if(user_input==1){
		coding_file << "HUFFMAN";
	}else if(user_input==2){
		coding_file << "ARITHMETIC";
	}else{
		coding_file << "ARITHMETIC";
	}
	coding_file.close();
	return 0;
}
Algos::~Algos(){

}
