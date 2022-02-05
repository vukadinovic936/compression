#include <stdio.h>
#include <map>
#include <string>
#include <queue>
using namespace std;

class Node {

private:


public:
	Node(char ch, int freq, Node* left=0, Node* right=0){
		this->ch = ch;
		this->freq = freq;
		this->left = left;
		this->right = right;	
	}

	char ch;
	int freq;
	struct Node *left;
	struct Node *right;
};
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
	map<char,int> freq;
	priority_queue<Node*,vector<Node*>,myComp> pq;
	for(int i=0;i<text.length();i++){
		freq[text[i]]++;
	}	
	map<char,int>::iterator it;
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
void printTree(Node* pq){
	printf("%c: %d  ", pq->ch, pq->freq);
	if(pq->left!=0)
		printTree(pq->left);
	if(pq->right!=0)
		printTree(pq->right);
}
int main(){
	string txt1 = "ADBADEDBBDD";
	Node* pq = getHuffmanTree(txt1);
	printTree(pq);
}
