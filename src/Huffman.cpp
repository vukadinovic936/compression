#include "Huffman.h"
Huffman::Huffman(){

}
Huffman::~Huffman(){

}

std::string Huffman::add_binary(std::string a,std::string b){
	/*
	https://www.tutorialspoint.com/program-to-add-two-binary-strings-in-cplusplus
	*/
   std::string result = "";
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
void Huffman::getHuffmanCoding(Node* root, std::unordered_map<char,std::string> &hashmap, code &coding){

		std::queue<std::pair<Node*,std::string>> q;
	    q.push(std::make_pair(root, ""));
		//bfs
		while(!q.empty()) {

			std::pair<Node*,std::string> u = q.front();
			if(u.first->ch != '\0'){
				hashmap[u.first->ch] = u.second ;
				coding.push_back(std::make_pair(u.first->ch, u.second.length()));
			}
			q.pop();

			if(u.first->getLeft())
				q.push(make_pair(u.first->getLeft(), u.second+"0"));

			if(u.first->getRight())
				q.push(make_pair(u.first->getRight(), u.second+"1"));

		}
	}
Node* Huffman::getHuffmanTree(std::string text){
	std::unordered_map<char,int> freq;
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

	for(int i=0;i<text.length();i++){
		freq[text[i]]++;
	}	
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
std::pair<std::string,code> Huffman::compress(std::string txt){
	std::unordered_map<char,std::string> hashmap;
	code coding;
	this->getHuffmanCoding(this->getHuffmanTree(txt),hashmap, coding);
	std::string compressed_string = "";
	for(char c : txt){
		compressed_string+=hashmap[c];
	}
	return make_pair(compressed_string,coding);
}
std::string Huffman::uncompress(std::string txt, code coding){
	// we need a hashmap from string to char	
	std::unordered_map<std::string,char> uncompress_code;
	std::string uncompressed_string;
	int cur_size = coding[0].second;
	std::string el_code = std::string(cur_size, '0');
	for(auto i: coding){
	
		if(i.second>cur_size){
			cur_size=i.second;
			el_code = el_code+"0";
		}
		uncompress_code[el_code] = i.first;

		el_code = this->add_binary(el_code, "1");	
	}
	el_code = "";
	for(char c: txt){
		el_code+=c;
		if(uncompress_code.count(el_code)){
			uncompressed_string+=uncompress_code[el_code];	
			el_code="";
		}
	}
	return uncompressed_string;
}


