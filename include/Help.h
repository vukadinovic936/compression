#ifndef HELP_H
#define HELP_H
#include <string>
#include <iostream>
#include "Command.h"
#include "StringsId.h"

class Help:public Command
{
	public:
		Help();
		Help(std::string name, std::string description);
		virtual ~Help();
		int run();

	private:
		std::string name;
		std::string description;
};

#endif
