#include <string>
#include <iostream>
#include "CommandFactory.h"
#include "StringsId.h"
#include "Node.h"
#include "Huffman.h"
#include <unordered_map>
#include <queue>


using namespace std;

struct myComp {
    constexpr bool operator()(
        Node* const& a,
        Node* const& b)
        const noexcept
    {
        return a->freq > b->freq;
    }
};

Node* getHuffmanTree(string text){
	unordered_map<char,int> freq;
	priority_queue<Node*,vector<Node*>,myComp> pq;
	for(int i=0;i<text.length();i++){
		freq[text[i]]++;
	}	
	unordered_map<char,int>::iterator it;
	for(it=freq.begin();it!=freq.end();it++){
		pq.push(new Node(it->first,it->second));
		printf("%c:%d\n",it->first,it->second);
	}
	while(pq.size()>1){
		Node* left = pq.top();
		pq.pop();
		Node* right = pq.top();
		pq.pop();
		pq.push(new Node('\0',left->freq+right->freq,left,right));
	}
	return pq.top();
}

int main(int argc, char** argv){

	//string txt1 = "0123456789";
	std::string txt1 = "ADBADEDBBDD";
	Huffman *t = new Huffman();

	pair<string,code> res = t->compress(txt1);
	string compressed_string=res.first;
	code coding = res.second;
	cout << "COMPRESSED STRING IS" << endl;
	cout << compressed_string << endl;

	string uncompressed_string = t->uncompress(compressed_string, coding);
	cout << endl;
	cout << "Uncompressed string is" << endl;
	cout << uncompressed_string << endl;
	return 0;
	try{
		std::string commandName = argv[1];
		CommandFactory fac(commandName);	
		fac.getCommand()->run();
	}catch(exception e){
		CommandFactory fac(STRINGS_HELP_COMMAND);	
		fac.getCommand()->run();
	}
	return 0;
}
