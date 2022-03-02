#include "Node.h"
Node::Node(char ch, int freq){
	this->ch=ch;
	this->freq=freq;
	this->left=NULL;
	this->right=NULL;
}
Node::Node(char ch, int freq, Node* left, Node* right){
	this->ch=ch;
	this->freq=freq;
	this->left=left;
	this->right=right;
}

Node* Node::getLeft(){
	return this->left;
}

Node* Node::getRight(){
	return this->right;
}
void Node::setLeft(Node* n){
	this->left=n;	
}
void Node::setRight(Node* n){
	this->right=n;
}
int Node::height(){
		int left_height=0;
		int right_height=0;
		if(this->getLeft()) left_height=this->getLeft()->height()+1;
		if(this->getRight()) right_height=this->getRight()->height()+1;
		return std::max(left_height,right_height);
}
void Node::inOrder(){
	if(this->left){
		this->left->inOrder();
	}	
	printf("%c",this->ch);
	if(this->right){
		this->right->inOrder();
	}
}
void Node::printTreeUtil(int space){
		if (this == NULL)
			return;
	
		// Increase distance between levels
		space += 10;
	
		// Process right child first
		if(this->getRight())
			this->getRight()->printTreeUtil(space);
	
		// Print current node after space
		// count
		printf("\n");
		printf("%*s", space-10,"");
		if(this->ch=='\0')
			printf("dot");
		else if(isblank(this->ch))
			printf("empty");
		else
			printf("%c\n",this->ch);
	
		// Process left child
		if(this->getLeft())
			this->getLeft()->printTreeUtil(space);
}
void Node::printTree(){
	this->printTreeUtil(0);
}
Node::~Node(){

}
