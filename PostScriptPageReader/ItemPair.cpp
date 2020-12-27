#include "ItemPair.h"

ItemPair::ItemPair(std::string const&paperName){
	this->paperName = paperName;
}

std::string ItemPair::get_paperName()
{
	return std::string(paperName);
}

void ItemPair::set_paperName(std::string const&paperName)
{
	this->paperName = paperName;
}

void ItemPair::Append(std::string const &s) {
	pageList.append(s);
}

void ItemPair::PrintList() {
	printf(pageList.c_str());
}

void ItemPair::AddComma(){

	if (pageList.empty()){
		return;
	}
	pageList.append(",");
}
