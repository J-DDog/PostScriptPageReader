#pragma once

#include <string>
#include <vector>

class ItemPair{
public:
	ItemPair (std::string const&paperName);

	std::string get_paperName();
	void set_paperName(std::string const&paperName);

	void Append(std::string const&s);
	void PrintList();
	void AddComma();
private:
	std::string paperName;
	std::string pageList;
};

