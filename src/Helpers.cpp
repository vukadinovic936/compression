#include "Helpers.h"

using namespace Helpers;

std::string Helpers::read_file(std::string file_path){
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