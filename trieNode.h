#ifndef __TRIENODE_H__
#define __TRIENODE_H__

#include <unordered_map>

struct TrieNode {
    TrieNode() { flag = false; }
    std::unordered_map<char, TrieNode*> table;
    bool flag;
};

#endif
