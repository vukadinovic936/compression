#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
using namespace std;
std::string exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}
bool test_algo(std::string algo_name){
	
	printf("Testing %s\n",algo_name.c_str());
	exec( ("./zeno algos "+algo_name).c_str());
	// get number of files in test/ directory
	int n = 3;
	for(int i=0;i<n;i++){
		printf("Running test %d\n", i+1);
		exec( ("./zeno compress test/test" + std::to_string(i+1) + ".txt").c_str() );
		exec( ("./zeno uncompress test/test" + std::to_string(i+1) + ".zen").c_str() );
		// cmp --silent test/test" +std::to_string(i+1)+ ".txt test/test" + std::to_string(i+1) + "_decoded.txt || echo \"files are different\"
		string res = exec( ( "cmp --silent test/test" +std::to_string(i+1)+ ".txt test/test" + std::to_string(i+1) + "_decoded.txt || echo \"files are different\" ").c_str() );
		if(res.size()>4){
			printf("Test %d failed\n",i+1);
			cout << res << endl;
		}else{
			printf("Test %d passed\n",i+1);
		}
	}

	return true;
}
int main(){
	test_algo("ARITHMETIC");
	printf("\n");
	test_algo("HUFFMAN");
	return 0;
}