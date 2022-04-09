#include "Helpers.h"

using namespace Helpers;

void Helpers::write_file(std::string file_path, std::string content){

	clear_file(file_path);
	append_to_file(file_path,content);

}
void Helpers::append_to_file(std::string file_path, std::string content){
	std::ofstream myfile;
	myfile.open (file_path, std::ios_base::app);
	myfile << content;
	myfile.close();
}
std::string Helpers::read_file(std::string path) {
    auto ss = ostringstream{};
    std::ifstream input_file(path);
    if (!input_file.is_open()) {
        std::cerr << "Could not open the file - '"
             << path << "'" << std::endl;
        exit(EXIT_FAILURE);
    }
    ss << input_file.rdbuf();
    return ss.str();
}
std::string Helpers::move_by(std::string a, int by){
	for(int i=0;i<by;i++){
		a+="0";
	}
	return a;
}
std:: string Helpers::subtract_binary(std::string a, std::string b){
	std::string result = "";
	int carry = 0;
	int i = a.length()-1;
	int j = b.length()-1;
	while(i>=0 || j>=0){
		int x = 0;
		int y = 0;
		if(i>=0){
			x = a[i]-'0';
		}
		if(j>=0){
			y = b[j]-'0';
		}
		int z = x-y-carry;
		if(z<0){
			z+=2;
			carry = 1;
		}else{
			carry = 0;
		}
		result = std::to_string(z)+result;
		i--;
		j--;
	}
	return result;
}
std::string Helpers::add_binary(std::string a,std::string b){
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
double Helpers::get_entropy(std::unordered_map<char,int> freq){
	double entropy = 0;
	double total=0;
	for(auto it = freq.begin(); it!=freq.end(); it++){
		total+= (double)it->second;
	}
	for(auto it = freq.begin(); it!=freq.end(); it++){
		double p = (double)it->second/total;
		entropy += p*log2(p);
	}
	return -entropy;
}
void Helpers::clear_file(std::string file_path){
	std::ofstream ofs;
	ofs.open(file_path, std::ofstream::out | std::ofstream::trunc);
	ofs.close();
}
bool Helpers::test_algo(std::string algo_name){
	
	printf("Testing %s\n",algo_name.c_str());
	system("./zeno algos");
	//system("1");
	// get number of files in test/ directory
	//int n = 3;
	//for(int i=0;i<n;i++){
	//	printf("Running test %d",i+1);
	//	system( ("./zeno compress test/test" + std::to_string(i+1) + ".txt").c_str() );
	//	system( ("./zeno uncompress test/test" + std::to_string(i+1) + ".zen").c_str() );
	//}

	return true;
}
std::vector<std::string> Helpers::split(std::string str, char delimiter){
	std::vector<std::string> result;
	std::stringstream ss(str);
	std::string token;
	while(std::getline(ss, token, delimiter)){
		result.push_back(token);
	}
	return result;
}
std::string Helpers::exec(const char* cmd){
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