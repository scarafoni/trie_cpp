all: trie

trie: trie_test.cc trie.h
	g++ $< -o $@

clean:
	rm *.o
