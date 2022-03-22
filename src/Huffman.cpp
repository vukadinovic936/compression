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
	std::unordered_map<char, int> freq;
	for(int i=0;i<txt.length();i++){
		freq[txt[i]]++;
	}
	std::unordered_map<char,std::string> hashmap;
	code coding;
	Node *root = this->getHuffmanTree(txt,freq);
	root->printTree();
	this->getHuffmanCoding(root,hashmap, coding);
	std::string compressed_string = "";
	for(char c : txt){
		compressed_string+=hashmap[c];
	}
	printf("Score is %f \n",this->score);
	write_file(output_file,compressed_string);
	//write to temp.txt
}
void Huffman::uncompress(std::string input_file, std::string output_file){
//	// we need a hashmap from string to char	
//	std::unordered_map<std::string,char> uncompress_code;
//	std::string uncompressed_string;
//	int cur_size = coding[0].second;
//	std::string el_code = std::string(cur_size, '0');
//	for(auto i: coding){
//	
//		if(i.second>cur_size){
//			for(int j=0;j<i.second-cur_size;j++)
//				el_code = el_code+ "0";
//			cur_size=i.second;
//		}else if(i.second<cur_size){
//			for(int j=0;j< cur_size-i.second;j++)
//				el_code.pop_back();
//			cur_size=i.second;
//		}
//		uncompress_code[el_code] = i.first;
//
//		el_code = add_binary(el_code, "1");	
//	}
//	el_code = "";
//	for(char c: txt){
//		el_code+=c;
//		if(uncompress_code.count(el_code)){
//			uncompressed_string+=uncompress_code[el_code];	
//			el_code="";
//		}
//	}
//	return uncompressed_string;
}

