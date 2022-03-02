#include <stdio.h>
#include <unordered_map>
#include <string>
#include <queue>
#include <iostream>
#include <math.h>
#include <string.h>
#include <stack>
#include <iostream>
#include <fstream>
#include <iostream>
#include <stdio.h>
using namespace std;
#define COUNT 10
class Node {

private:
public:
	Node(char ch, int freq){
		this->ch = ch;
		this->freq=freq;
	}
	Node(char ch, int freq, Node* left, Node* right){
		this->ch = ch;
		this->freq = freq;
		this->left = left;
		this->right = right;
	}
	int height(){	
		int left_height=0;
		int right_height=0;
		if(this->left) left_height=this->left->height()+1;
		if(this->right) right_height=this->right->height()+1;
		return max(left_height, right_height);
	}
	void printTreeUtil(int space){
			// Base case
			if (this == NULL)
				return;
		
			// Increase distance between levels
			space += 10;
		
			// Process right child first
			this->right->printTreeUtil(space);
		
			// Print current node after space
			// count
			printf("\n");
			printf("%*s", space-10,"");
			if(this->ch == ' ' ){
				printf("empt");
			}else
			printf("%c\n",this->ch);
		
			// Process left child
			this->left->printTreeUtil(space);
	}
	// Wrapper over print2DUtil()
	void printTree()
	{
		this->printTreeUtil(0);
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
std::string read_file(std::string file_path){
	std::string txt = "";
	std::string line;
	std::ifstream myfile(file_path);
	if (myfile.is_open())
	{
		while ( getline (myfile,line) )
		{
			txt+=line;
		}
		myfile.close();
	}else{
		std::cout << "Unable to open file" << std::endl;
	} 
	return txt;

}
Node* getHuffmanTree(string text){
	unordered_map<char,int> freq;
	priority_queue<Node*,vector<Node*>,myComp> pq;
	for(int i=0;i<text.length();i++){
		freq[text[i]]++;
	}	
	cout << text << endl;
	unordered_map<char,int>::iterator it;
	for(it=freq.begin();it!=freq.end();it++){
		pq.push(new Node(it->first,it->second));
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
void getHuffmanCoding(Node* root, unordered_map<char,string> &hashmap, vector<pair<char,int>> &code){

		stack<pair<Node*,string>> q;
	    q.push(make_pair(root, ""));
		//bfs
		while(!q.empty()) {

			pair<Node*,string> u = q.top();
			q.pop();

			if(u.first->right)
				q.push(make_pair(u.first->right, u.second+"1"));

			if(u.first->ch != '\0'){
				hashmap[u.first->ch] = u.second ;
				code.push_back(make_pair(u.first->ch, u.second.length()));
			}

			if(u.first->left)
				q.push(make_pair(u.first->left, u.second+"0"));



		}
	}	
void compress(string txt, vector<pair<char,int>> &code, string &compressed_string){

	unordered_map<char,string> hashmap;
	getHuffmanCoding(getHuffmanTree(txt), hashmap, code);

	for(auto i:hashmap){
		cout << i.first << " " << i.second << endl;
	}
	// for each char in txt replace it with it's code
	compressed_string = "";
	for(char c : txt){
		compressed_string+=hashmap[c];
	}
}
string add_binary(string a, string b){
	/*
	https://www.tutorialspoint.com/program-to-add-two-binary-strings-in-cplusplus
	*/
   string result = "";
   int temp = 0;
   int size_a = a.size() - 1;
   int size_b = b.size() - 1;
   while (size_a >= 0 || size_b >= 0 || temp == 1){
      temp += ((size_a >= 0)? a[size_a] - '0': 0);
      temp += ((size_b >= 0)? b[size_b] - '0': 0);
      result = char(temp % 2 + '0') + result;
      temp /= 2;
      size_a--; size_b--;
   }
   return result;
}
void uncompress(string &compressed_string, string &uncompressed_string, vector<pair<char,int>>& code){
	// we need a hasmap from string to char	
	unordered_map<string,char> uncompress_code;
	int cur_size = code[0].second;
	string el_code = string(cur_size, '0');
	for(auto i: code){
		
		if(i.second>cur_size){
			for(int j=0;j<i.second-cur_size;j++)
				el_code = el_code+ "0";
			cur_size=i.second;
		}else if(i.second<cur_size){
			for(int j=0;j< cur_size-i.second;j++)
				el_code.pop_back();
			cur_size=i.second;
		}

		uncompress_code[el_code] = i.first;
		el_code = add_binary(el_code, "1");	
	}
	for(auto i : uncompress_code){
		cout << i.first << " " << i.second << endl;
	}
	el_code = "";
	for(char c: compressed_string){
		el_code+=c;
		if(uncompress_code.count(el_code)){
			uncompressed_string+=uncompress_code[el_code];	
			el_code="";
		}
	}

}


 
int main(int argc, char** argv){
	//string txt1 = "practically nothing towards, the upkeep of the nest, and then— Achilles: And of course there are soldiers-Glorious Fighters Against Communism!";
	string txt1 = "JA TE VOLIM A STA MOGU ME NA PUUUUUUT SALJEEEEE trykasknsdakjsadjksdbjnm oasdaskjis it nI will try many possibilities in case 000 is not the first string :O";
	cout <<  "COMPRESSING" << endl;
	cout << endl;
	string compressed_string = "";
	string uncompressed_string = "";
	vector<pair<char,int>> code;
	compress(txt1,code,compressed_string);
	for(auto i:code){
		cout << i.first << " " << i.second << endl;

	}

	cout << compressed_string << endl;
	cout << endl;
	cout <<  "NOW UNCOMPRESSING" << endl;
	cout << endl;
	uncompress(compressed_string, uncompressed_string, code );
	cout << uncompressed_string << endl;
}