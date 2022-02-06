#ifndef COMMAND_H
#define COMMAND_H
#include <string>

class Command
{
	public:
		Command();
		Command(std::string name, std::string description);
		virtual ~Command();
		virtual int run() = 0;
		std::string getName();
		std::string getDescription();

	private:
		std::string name;
		std::string description;
};

#endif 