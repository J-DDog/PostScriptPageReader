#include "FileHandler.h"

int FileHandler::CheckPaper(std::vector<ItemPair> &list, std::string const& paperName) {

	for (int i = 0; i < list.size(); i++) {
		if (list[i].get_paperName().compare(paperName) == 0) {
			return i;
		}
	}
	return -1;
}

void FileHandler::AddPages(ItemPair& itemPair, int pageNumber) {

	itemPair.AddComma();
	itemPair.Append(std::to_string(pageNumber));
	itemPair.Append("-");
	itemPair.Append(std::to_string(pageNumber + 1));
	
}

void FileHandler::AddPaperType(std::vector<ItemPair> &list, std::string const& paperName) {

	list.push_back(ItemPair(paperName));
}

void FileHandler::PrintList(std::vector<ItemPair>& list) {
	for (int i = 0; i < list.size(); i++) {
		printf("-----> %s <-----\n", list[i].get_paperName().c_str());
		list[i].PrintList();
		printf("\n");
		printf("-------------------------------------------------------\n");
	}
}

void FileHandler::LoadingBarCheckAndPrint() {
	if (clock()-timer >= CLOCKS_PER_SEC/2) {
		printf("=");
		timer = clock();
	}
}
