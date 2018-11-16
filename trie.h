#ifndef __TRIE_H__
#define __TRIE_H__

#include <vector>
#include <string>
#include <utility>
#include <memory>
#include <queue>
#include "trieNode.h"

struct Trie {
    Trie();
    void insert(const std::string& str);
    void build();
    std::shared_ptr<TrieNode> root;
};

#endif
