#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <ctime>
#include "trie.h"

void insertWords(std::ifstream& in, Trie& trie);
int getStrSize(const std::string& str);

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: ./filter file1 file2" << std::endl;
        std::cerr << "file1: file contains the words which are not allowed to show" << std::endl;
        std::cerr << "file2: file need to be filtered" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string wordFileStr(argv[1]);
    std::string inputFileStr(argv[2]);
    size_t dotPos = inputFileStr.find('.');
    std::string outputFileStr = inputFileStr.substr(0, dotPos) + "_filtered" + inputFileStr.substr(dotPos);
    
    clock_t startTime = clock();
    std::ifstream wordFile(wordFileStr.c_str());
    Trie trie;
    insertWords(wordFile, trie);
    wordFile.close();

    std::ifstream inputFile(inputFileStr.c_str());
    std::ofstream outputFile(outputFileStr.c_str());
    std::string str;

    while (std::getline(inputFile, str)) {
        int strPtr = 0;
        std::string currStr;
        while (strPtr < str.size()) {
            std::string temp = str.substr(strPtr); 
            auto result = trie.search(temp);
            if (result.first) {
                int length = getStrSize(temp.substr(0, result.second));
                currStr += std::string(length, 'x');
                strPtr += result.second;
            } else {
                currStr.push_back(str[strPtr++]);
            }
        }
        outputFile << currStr << std::endl;
    }
    clock_t endTime = clock();
    std::cout << "It took " << static_cast<double>(endTime - startTime)/CLOCKS_PER_SEC << " seconds." << std::endl;
    
    inputFile.close();
    outputFile.close();
    return 0;
}

void insertWords(std::ifstream& in, Trie& trie) {
    std::string str;
    while (std::getline(in, str)) {
        trie.insert(str);
    }
}

int getStrSize(const std::string& str) {
    int strPtr = 0;
    int length = 0;
    while (strPtr < str.size()) {
        char c = str[strPtr];
        ++length;
        if (((c >> 7) & 1) == 0) {
            ++strPtr;
        } else if (((c >> 5) & 7) == 6) {
            strPtr += 2;
        } else if (((c >> 4) & 15) == 14) {
            strPtr += 3;
        } else if (((c >> 3) & 31) == 30) {
            strPtr += 4;
        } else if (((c >> 2) & 63) == 62) {
            strPtr += 5;
        } else if (((c >> 1) & 127) == 126) {
            strPtr += 6;
        } else {
            std::cerr << "Error! Unidentified character!" << std::endl;
            exit(EXIT_FAILURE);
        }
    }
    return length;
}
