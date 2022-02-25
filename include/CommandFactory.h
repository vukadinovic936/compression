#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H

#include <iostream>
#include <string>
#include <iostream>

#include "CommandFactory.h"
#include "Algos.h"
#include "Compress.h"
#include "Uncompress.h"
#include "Help.h"
#include "StringsId.h"

class CommandFactory
{
	public:
		CommandFactory(std::string name);
		virtual ~CommandFactory();
		Command* getCommand();

	private:
		Command* command;
};

#endif 