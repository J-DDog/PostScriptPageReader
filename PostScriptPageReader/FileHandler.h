#pragma once
#include <string>
#include <vector>
#include <time.h>
#include <math.h>
#include "ItemPair.h"

class FileHandler{
public:
	int CheckPaper(std::vector<ItemPair> &list, std::string const &paperName);
	void AddPages(ItemPair &itemPair, int pageNumber);
	void AddPaperType(std::vector<ItemPair> &list, std::string const &paperName);
	void PrintList(std::vector<ItemPair> &list);
	void LoadingBarCheckAndPrint();
private:
	clock_t timer = clock();
};

