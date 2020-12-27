// PostScriptPageReader.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <fstream>
#include <vector>
#include "ItemPair.h"
#include "FileHandler.h"

int main(int argc, char** argv) {

	/*/Read Command line Arguments
	char* lineInput;
	for (int i = 1; i < argc; i++) {
		lineInput = argv[i];
		printf(lineInput);
		printf("\n");
	}
	/*/
	
	// Command Line Specified Papar
	if (argc == 3) {
		char* fileName = argv[1];
		char* paperStock = argv[2];

		int pageNumber = 0;
		int sizeOfLine = 0;
		std::string line;
		std::ifstream file;
		file.open(fileName);
		while (line != "%%EOF") {

			std::getline(file, line);

			//printf("%s\n",line.c_str());

			//Update Page number
			if (line.compare(0, 7, "%%Page:") == 0) {
				sizeOfLine = line.size();
				pageNumber = stoi(line.substr(10, sizeOfLine - 10));
			}
			//Update List
			else if (line.compare(0, 11, " /MediaType") == 0) {
				if (line.compare(13, line.find(")")-13, paperStock) == 0) {
					printf("%d-%d,", pageNumber, pageNumber+1);
				}
			}
		}
		printf("\n");
	}

	// All Paper Listed
	else if (argc == 2){

		char* fileName = argv[1];
		std::vector<ItemPair> list;
		FileHandler fileHandler;
		int listNumber;
		std::string paperName;

		int pageNumber = 0;
		int sizeOfLine = 0;
		std::string line;
		std::ifstream file;
		file.open(fileName);
		while (line != "%%EOF") {

			std::getline(file, line);

			fileHandler.LoadingBarCheckAndPrint();
			//printf("%s\n",line.c_str());

			//Update Page number
			if (line.compare(0, 7, "%%Page:") == 0) {
				sizeOfLine = line.size();
				pageNumber = stoi(line.substr(10, sizeOfLine - 10));
			}
			//Update List
			else if (line.compare(0, 11, " /MediaType") == 0) {
				paperName = line.substr(13, line.find(")") - 13);
				listNumber = fileHandler.CheckPaper(list, paperName);
				if (listNumber != -1) {
					fileHandler.AddPages(list[listNumber], pageNumber);
				}
				else if (listNumber == -1) {
					fileHandler.AddPaperType(list, paperName);
					fileHandler.AddPages(list[list.size()-1], pageNumber);
				}
				
			}
		}
		printf("\n");
		fileHandler.PrintList(list);

	}
	std::cin.clear();
	std::cin.sync();
	std::cin.get();

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
