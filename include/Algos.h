#ifndef ALGOS_H
#define ALGOS_H
#include <string>
#include <iostream>
#include "Command.h"

class Algos: public Command
{
	public:
		Algos();
		Algos(std::string name, std::string description);
		virtual ~Algos();
		int run();

	private:
		std::string name;
		std::string description;
};

#endif
