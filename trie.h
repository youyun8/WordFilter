#ifndef __TRIE_H__
#define __TRIE_H__

#include <vector>
#include <string>
#include <utility>
#include "trieNode.h"

class Trie {
public:
    Trie();
    ~Trie();
    void insert(const std::string& str);
    std::pair<bool, int> search(const std::string& str);
private:
    TrieNode* root;
    std::vector<TrieNode*> nodeList;
};

#endif
