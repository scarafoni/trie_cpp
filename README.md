trie_cpp
========
trie in c++ for storing large dictionaries

Manifest:
---------
	-trie.h: primary file containing the trie data structures
	-trie_test.cc: testing file for trie data structure
	-dictionary.txt: list of words for testing
	-Makefile: makefile for the program

Compilation Instructions
-----------------------
	-please compile with g++
	-"make" to compile
	-./trie to run

Structure Overview:
-------------------
	the program uses two classes, Trie_Node and Trie. The former is nested in the latter. Each node contains a STL map of chars to Trie_Node pointers (one per letter) to represent branching. 
