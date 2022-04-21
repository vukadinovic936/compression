#ifndef ALGOS_H
#define ALGOS_H
#include <string>
#include <iostream>
#include "Command.h"
#include <iostream>
#include <fstream>
#include "StringsId.h"
#include "Helpers.h"

using namespace Helpers;
class Algos: public Command
{
	public:
		Algos();
		Algos(std::string name, std::string description);
		virtual ~Algos();
		int run(std::string file_name="");

	private:
		std::string name;
		std::string description;
};

#endif
