#ifndef FILE_H
#define FILE_H
#include <string>

class File
{
	public:
		File();
		virtual ~File();
		std::string getName();
		std::string getDescription();

	private:
		std::string name;
		std::string description;
};

#endif 