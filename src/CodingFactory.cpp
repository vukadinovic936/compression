#include "CodingFactory.h"
CodingFactory::CodingFactory(){
	// get coding name
	std::string coding_name = read_file(STRINGS_CODING_FILE);
	if(coding_name == STRINGS_HUFFMAN_CODING){
		this->coding = new Huffman();
	}
}


CodingFactory::~CodingFactory(){

}

Coding* CodingFactory::getCoding(){
	return this->coding;
}
