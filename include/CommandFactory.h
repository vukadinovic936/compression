#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H
#include <string>
#include <Command.h>

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