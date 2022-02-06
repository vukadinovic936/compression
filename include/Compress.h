#ifndef COMPRESS_H
#define COMPRESS_H
#include <Command.h>
#include <string>
#include <iostream>

class Compress : public Command
{
	public:
		Compress();
		Compress(std::string name, std::string description);
		virtual ~Compress();
		int run();

	private:
		std::string name;
		std::string description;
};

#endif
