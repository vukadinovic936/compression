#include "Helpers.h"

using namespace Helpers;

std::string Helpers::read_file(std::string file_path){
	std::string txt = "";
	std::string line;
	std::ifstream myfile(file_path);
	if (myfile.is_open())
	{
		while ( getline (myfile,line) )
		{
			txt+=line;
		}
		myfile.close();
	}else{
		std::cout << "Unable to open file" << std::endl;
	} 
	return txt;

}