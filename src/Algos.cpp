#include "Algos.h"
Algos::Algos(){

}

Algos::Algos(std::string name, std::string description):Command(name, description){

}

int Algos::run(){
	printf("SELECT THE CODE YOU WANT TO USE\n");
	printf("1: HUFFMAN\n");
	printf("2: ARITHMETIC\n");
	int user_input;
	scanf("%d",&user_input);

	std::ofstream coding_file;
	coding_file.open("coding.txt");
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
