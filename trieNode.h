#ifndef __TRIENODE_H__
#define __TRIENODE_H__

#include <unordered_map>
#include <memory>

struct TrieNode {
    TrieNode() {
        suffix = nullptr;
        flag = false;
        length = 0;
    }
    std::unordered_map<char, std::shared_ptr<TrieNode>> table;
    std::shared_ptr<TrieNode> suffix;
    bool flag;
    int length;
};

#endif
