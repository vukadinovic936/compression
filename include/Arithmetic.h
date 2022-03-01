#ifndef ARITHMETIC_H
#define ARITHMETIC_H
#include <string>
#include <string.h>
#include <unordered_map>
#include <vector>
#include <queue>

#include "Algos.h"
#include "Node.h"
#include "Coding.h"

class Arithmetic : public Coding
{
	public:
		Arithmetic();
		virtual ~Arithmetic();
		std::pair<std::string,code> compress(std::string txt, std::unordered_map<char, int> freq);
		std::string uncompress(std::string txt, code coding);

	private:
		std::string name;
		std::string description;
};

#endif
