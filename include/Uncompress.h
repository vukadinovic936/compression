#ifndef UNCOMPRESS_H
#define UNCOMPRESS_H
#include <string>
#include <iostream>
#include "Command.h"
#include "Helpers.h"
#include "CodingFactory.h"

class Uncompress: public Command
{
	public:
		Uncompress();
		Uncompress(std::string name, std::string description);
		virtual ~Uncompress();
		int run(std::string file_name);

	private:
		std::string name;
		std::string description;
};

#endif
