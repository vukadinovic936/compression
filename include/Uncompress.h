#ifndef UNCOMPRESS_H
#define UNCOMPRESS_H
#include <string>
#include <iostream>
#include "Command.h"

class Uncompress: public Command
{
	public:
		Uncompress();
		Uncompress(std::string name, std::string description);
		virtual ~Uncompress();
		int run();

	private:
		std::string name;
		std::string description;
};

#endif
