#ifndef CODINGFACTORY_H
#define CODINGFACTORY_H

#include <string>

#include "Helpers.h"
#include "Coding.h"
#include "Huffman.h"
#include "StringsId.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <iostream>

using namespace Helpers;
class CodingFactory
{
	public:
		CodingFactory();
		virtual ~CodingFactory();
		Coding* getCoding();

	private:
		Coding* coding;
};

#endif
