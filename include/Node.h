#ifndef NODE_H
#define NODE_H
#include <string>
#include <stdio.h>
#include <math.h>
#include <string.h>

class Node
{
	public:
		Node(char ch, int freq);
		Node(char ch, int freq, Node* left, Node* right);
		virtual ~Node();

		int height();
		void printTree();
		void inOrder();
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
