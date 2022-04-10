#include "CodingFactory.h"
CodingFactory::CodingFactory(){
	// get coding name
	std::string coding_name = read_file( join_paths(STRINGS_WORKING_DIR , std::string(STRINGS_CODING_FILE)));
	if(coding_name == STRINGS_HUFFMAN_CODING){
		this->coding = new Huffman();
	}else if(coding_name == STRINGS_ARITHMETIC){
		this->coding = new Arithmetic();
	}
}


CodingFactory::~CodingFactory(){

}

Coding* CodingFactory::getCoding(){;
	return this->coding;
}
