#ifndef HUFFMAN_H
#define HUFFMAN_H
#include "Algos.h"
#include "Node.h"
#include <string>
#include <string.h>
#include <unordered_map>
#include <vector>
#include <queue>
//#include "Utils.h"

#define code std::vector<std::pair<char,int>> 


class Huffman
{
	public:
		Huffman();
		std::pair<std::string,code> compress(std::string txt);
		std::string uncompress(std::string txt, code);
		virtual ~Huffman();

	private:
		std::string add_binary(std::string a, std::string b);
		std::string name;
		std::string description;
		Node* getHuffmanTree(std::string txt);
		void getHuffmanCoding(Node* root, std::unordered_map<char,std::string> &hashmap, code &coding);
};

#endif
