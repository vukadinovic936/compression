#ifndef COMPRESS_H
#define COMPRESS_H
#include <string>
#include <iostream>
#include <unordered_map>
#include <queue>

#include "Huffman.h"
#include "Command.h"
#include "CodingFactory.h"

using namespace Helpers;

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
