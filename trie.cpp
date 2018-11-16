#include "trie.h"

Trie::Trie() {
    root = std::make_shared<TrieNode>();
}

void Trie::insert(const std::string& str) {
    auto currNode = root;
    int length = 0;
    for (int idx = 0; idx < str.size(); ++idx) {
        if ((currNode->table).count(str[idx]) == 0) {
            (currNode->table)[str[idx]] = std::make_shared<TrieNode>();
        }
        currNode = (currNode->table)[str[idx]];
        currNode->length = ++length;
    }
    currNode->flag = true;
}

void Trie::build() {
    std::queue<std::shared_ptr<TrieNode>> que;
    que.push(root);

    while (!que.empty()) {
        auto currNode = que.front();
        que.pop();
        for (auto iter = currNode->table.begin(); iter != currNode->table.end();++iter) {
            char nextC = iter->first;
            auto nextPtr = currNode->suffix;
            while (nextPtr != nullptr && nextPtr->table.count(nextC) == 0) {
                nextPtr = nextPtr->suffix;
            }
            iter->second->suffix = nextPtr != nullptr? (nextPtr->table)[nextC]: root;
            que.push(iter->second);
        }
    }
}
