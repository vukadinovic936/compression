#ifndef CODING_H
#define CODING_H
#include <string>
#include <string>
#include <string.h>
#include <unordered_map>
#include <vector>
#include <queue>
#include <StringsId.h>
#include "Node.h"


class Coding
{
	public:
		Coding();
		virtual ~Coding();
		virtual void compress(std::string input_path, std::string output_path);
		virtual void uncompress(std::string input_path, std::string output_path);

	private:
		std::string name;
		std::string description;
		double score;
};

#endif
