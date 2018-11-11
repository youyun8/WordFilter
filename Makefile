all: filter.o trie.o
	g++ filter.o trie.o -o filter
filter.o: filter.cpp trie.h
	g++ -std=c++11 -c filter.cpp -o filter.o
trie.o: trie.cpp trie.h trieNode.h
	g++ -std=c++11 -c trie.cpp -o trie.o
clean:
	rm *.o filter