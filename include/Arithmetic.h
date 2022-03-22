#ifndef ARITHMETIC_H
#define ARITHMETIC_H
#include <string>
#include <string.h>
#include <unordered_map>
#include <vector>
#include <queue>
#include <BigFloat.h>
#include "Algos.h"
#include "Node.h"
#include "Coding.h"
#include "Helpers.h"
#include "StringsId.h"
#include <cstdio>

using namespace Helpers;
class Arithmetic : public Coding
{
	public:
		Arithmetic();
		virtual ~Arithmetic();

		void compress(std::string input_path, std::string output_path);
		void uncompress(std::string input_path, std::string output_path);

	private:
		std::string name;
		std::string description;

};

#endif
