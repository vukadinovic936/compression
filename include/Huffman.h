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

#define code std::vector<std::pair<char,int>> 

using namespace Helpers;
class Huffman: public Coding 
{
	public:
		Huffman();
		void compress(std::string input_path, std::string outout_path);
		void uncompress(std::string input_path, std::string output_path);
		virtual ~Huffman();
		

	private:
		std::string name;
		std::string description;
		double score;
		Node* getHuffmanTree(std::string txt, std::unordered_map<char,int> freq);
		void getHuffmanCoding(Node* root, std::unordered_map<char,std::string> &hashmap, code &coding);
		void recoverHuffmanCoding(Node *root, std::unordered_map<std::string, char> &hashmap, code &coding);
};

#endif
