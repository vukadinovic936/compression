#ifndef CODING_H
#define CODING_H
#include <string>
#include <string>
#include <string.h>
#include <unordered_map>
#include <vector>
#include <queue>

#include "Node.h"

#define code std::vector<std::pair<char,int>> 

class Coding
{
	public:
		Coding();
		virtual ~Coding();
		virtual std::pair<std::string,code> compress(std::string txt) = 0;
		virtual std::string uncompress(std::string txt, code coding) = 0;
	private:
		std::string name;
		std::string description;
};

#endif
