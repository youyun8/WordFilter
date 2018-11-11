#include "trie.h"

Trie::Trie() {
    root = new TrieNode;
    nodeList.push_back(root);
}

Trie::~Trie() {
    for (int idx = 0; idx < nodeList.size(); ++idx) {
        delete nodeList[idx];
    }
}

void Trie::insert(const std::string& str) {
    TrieNode* currNode = root;
    for (int idx = 0; idx < str.size(); ++idx) {
        if ((currNode->table).count(str[idx]) == 0) {
            (currNode->table)[str[idx]] = new TrieNode;
            nodeList.push_back((currNode->table)[str[idx]]);
        }
        currNode = (currNode->table)[str[idx]];
    }
    currNode->flag = true;
}

std::pair<bool, int> Trie::search(const std::string& str) {
    bool isFound = false;
    int length = 0;
    TrieNode* currNode = root;
    for (int idx = 0; idx < str.size(); ++idx) {
        if ((currNode->table).count(str[idx]) == 0) {
            break;
        }
        ++length;
        currNode = (currNode->table)[str[idx]];
    }
    isFound = currNode->flag;
    return std::make_pair(isFound, length);
}
