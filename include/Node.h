#ifndef NODE_H
#define NODE_H
#include <string>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <bitset>
#include <stack>

class Node
{
	public:
		Node(char ch, int freq);
		Node(char ch, int freq, Node* left, Node* right);
		virtual ~Node();

		int height();
		void printTree();
		void inOrder();
		void export_tree(std::string &s);
		void import_tree(std::string s, int &cutoff);
		Node* getLeft();
		Node* getRight();

		void setLeft(Node* n);
		void setRight(Node* n);

		char ch;
		int freq;
	private:
		void printTreeUtil(int space);
		Node* left;
		Node* right;

};

#endif
