#ifndef HUFFMAN_H
#define HUFFMAN_H
#include <string>
#include <string.h>
#include <unordered_map>
#include <vector>
#include <stack>

#include "Algos.h"
#include "Node.h"
#include "Coding.h"
#include "Helpers.h"

//#include "Utils.h"
using namespace Helpers;
class Huffman: public Coding 
{
	public:
		Huffman();
		std::pair<std::string,code> compress(std::string txt, std::unordered_map<char, int> freq);
		std::string uncompress(std::string txt, code coding);
		virtual ~Huffman();

	private:
		std::string name;
		std::string description;
		double score;
		Node* getHuffmanTree(std::string txt, std::unordered_map<char,int> freq);
		void getHuffmanCoding(Node* root, std::unordered_map<char,std::string> &hashmap, code &coding);
};

#endif
