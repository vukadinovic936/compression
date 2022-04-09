#include "Huffman.h"
Huffman::Huffman(){

}
Huffman::~Huffman(){

}


void Huffman::getHuffmanCoding(Node* root, std::unordered_map<char,std::string> &hashmap, code &coding){

		std::stack<std::pair<Node*,std::string>> q;
	    q.push(std::make_pair(root, ""));
		//bfs
		while(!q.empty()) {

			std::pair<Node*,std::string> u = q.top();

			q.pop();

			if(u.first->getRight())
				q.push(make_pair(u.first->getRight(), u.second+"1"));


			if(u.first->ch != '\0'){
				hashmap[u.first->ch] = u.second ;
				this->score += u.second.length();
				coding.push_back(std::make_pair(u.first->ch, u.second.length()));
			}

			if(u.first->getLeft())
				q.push(make_pair(u.first->getLeft(), u.second+"0"));
		}
		this->score = score/hashmap.size();
}
void Huffman::recoverHuffmanCoding(Node *root, std::unordered_map<std::string, char> &hashmap, code &coding){

		std::stack<std::pair<Node*,std::string>> q;
	    q.push(std::make_pair(root, ""));
		//bfs
		while(!q.empty()) {

			std::pair<Node*,std::string> u = q.top();

			q.pop();

			if(u.first->getRight())
				q.push(make_pair(u.first->getRight(), u.second+"1"));


			if(u.first->ch != '\0'){
				hashmap[u.second] = u.first->ch;
				this->score += u.second.length();
				coding.push_back(std::make_pair(u.first->ch, u.second.length()));
			}

			if(u.first->getLeft())
				q.push(make_pair(u.first->getLeft(), u.second+"0"));
		}
		this->score = score/hashmap.size();
}
Node* Huffman::getHuffmanTree(std::string text,std::unordered_map<char,int> freq){
	struct myComp {
		constexpr bool operator()(
			Node* const& a,
			Node* const& b)
			const noexcept
		{
			return a->freq > b->freq;
		}
	};
	std::priority_queue<Node*,std::vector<Node*>,myComp> pq;
	std::unordered_map<char,int>::iterator it;
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
void Huffman::compress(std::string input_file, std::string output_file){ //  std::unordered_map<char,int> freq){

	std::string txt = read_file(input_file);
	std::cout << txt << std::endl;
	std::unordered_map<char, int> freq;
	for(int i=0;i<txt.length();i++){
		freq[txt[i]]++;
	}
	std::unordered_map<char,std::string> hashmap;
	code coding;
	Node *root = this->getHuffmanTree(txt,freq);
	root->printTree();
	this->getHuffmanCoding(root,hashmap, coding);
	for(auto c:hashmap){
		std::cout << c.first << " " << c.second << std::endl;
	}
	std::string compressed_string = "";
	for(char c : txt){
		compressed_string+=hashmap[c];
	}
	printf("Score is %f \n",this->score);	
	std::string exported_tree="";
	root->export_tree(exported_tree);
	exported_tree = exported_tree+"0"+compressed_string;
	// add write to a binary file
	write_file(output_file,exported_tree);
	//take output file in txt and dump it to a binary zen
	exec( ("python lib/string_to_binary.py "+output_file).c_str());
}
void Huffman::uncompress(std::string input_file, std::string output_file){
	//take output file in .zen and dump it to .txt
	// add read from a binary file
	exec( ("python lib/binary_to_string.py "+input_file).c_str());
	std::string encoded_txt = read_file(input_file);	
	Node *new_root = new Node('\0',0);
	int cutoff=0;
	new_root->import_tree(encoded_txt, cutoff);
	encoded_txt = encoded_txt.substr(cutoff+1, encoded_txt.length()-cutoff);
	new_root->printTree();

	std::unordered_map<std::string, char> hashmap2;
	code coding2;
	this->recoverHuffmanCoding(new_root,hashmap2, coding2);
	for(auto c:hashmap2){
		std::cout << c.first << " " << c.second << std::endl;
	}
	std::string el_code = "";
	std::string uncompressed_string = "";
	for(char c: encoded_txt){
		el_code+=c;
		if(hashmap2.count(el_code)){
			uncompressed_string+=hashmap2[el_code];	
			el_code="";
		}
	}
	std::cout << uncompressed_string << std::endl;
	write_file(output_file,uncompressed_string);
}

