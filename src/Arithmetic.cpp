#include "Arithmetic.h"
#include <map>
using namespace std;
Arithmetic::Arithmetic(){
	
}
Arithmetic::~Arithmetic(){

}

std::pair<std::string,code> Arithmetic::compress(std::string txt, std::unordered_map<char,int> freq){
	
	// Convert frequencies in probabilities
	int total=0;
	for(auto i: freq){
		total+=i.second;
	}
	// add one for end-of-data
	total+=1;
	// first element in the pair is cumulative probability, second is symbol probability
	std::unordered_map<char,std::pair<double,double>> probs;
	std::map<double,std::pair<char,double>> set2;
	double cum_prob=0.0;
	for(auto i: freq){
		probs[i.first] = std::make_pair(cum_prob, (double) i.second/ (double) total);
		set2[cum_prob] = std::make_pair(i.first, (double) i.second/ (double) total);
		cum_prob+= ( (double) i.second / (double) total);
	}
	set2[cum_prob] = std::make_pair('\0', (double) 1 / (double) total);
	probs['\0'] = std::make_pair(cum_prob,(double) 1/ (double) total);
	// starting point
	double C=0.0;
	// interval size
	double A=1.0;
	for(char c: txt){
		C = C + (A * probs[c].first); 
		A = A * probs[c].second;
	}
	C = C + (A * probs['\0'].first);
	A = A * probs['\0'].second;
	printf("ENCODE\n");
	printf("%.12f", C);
	// Constructing the table needed symbol | cum_prob | symbol prob | length 
	printf("NOW DECODE\n");
	std::string decoded = "";
	bool end_file=false;
	while(!end_file){
		int set_size = set2.size();
		int cnt=0;
		for(auto row = set2.begin(); row != set2.end(); row++){
			if((C) < row->first){
				row--;
				decoded += row->second.first;
				C = C - row->first;
				C = C * (1/row->second.second);
				if(row->second.first == '\0'){
					end_file=true;
				}
				break;
			}
			cnt++;
			if(cnt==set_size){
				end_file=true;	
			}
		}	
		//cnt++;
	}
	cout << decoded << endl;
	code coding;
	std::string s = "AS";
	return make_pair(s, coding);
}
std::string Arithmetic::uncompress(std::string txt, code coding){
	return "sth";
}
