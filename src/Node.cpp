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

void Node::export_tree(std::string &s){
	if(this->left){
		this->left->export_tree(s);
	}
	if(this->right){
		this->right->export_tree(s);
	}
	if(this->ch == '\0'){
		s+='0';
	}else{
		s+='1';
		s+=std::bitset<8>(this->ch).to_string();
	}
}

void Node::import_tree(std::string s, int &cutoff){
	std::stack<Node*> st;	
	for(int i=0;i<s.length();i++){

		if(s[i]=='1'){
			std::string temp="";
			for(int j=1;j<=8;j++){
				temp+=s[i+j];
			}
			st.push( new Node(static_cast<char>(std::bitset<8>(temp).to_ulong()), 0 )); 
			i+=8;
		}else if(s[i]=='0'){
			if(st.size()==1){
				this->ch=st.top()->ch;
				this->freq=st.top()->freq;
				this->left=st.top()->left;
				this->right=st.top()->right;
				cutoff=i;
				break;
			}else{
				Node* a = st.top();
				st.pop();
				Node* b = st.top();
				st.pop();
				st.push(new Node('\0',0,b,a));
			}
		}

	}
	this->ch=st.top()->ch;
	this->freq=st.top()->freq;
	this->left=st.top()->left;
	this->right=st.top()->right;
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
