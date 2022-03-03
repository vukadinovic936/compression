//helpers.h
#include <string>

#include <iostream>
#include <fstream>
#include <iostream>
#include <stdio.h>
#pragma once
namespace Helpers{
	std::string read_file(std::string file_path);
	std::string add_binary(std::string a,std::string b);
	std::string subtract_binary(std::string a, std::string b);
	std::string move_by(std::string a, int by);
}