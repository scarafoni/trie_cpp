#include <iostream>
#include <string>
#include "trie.h"
#include <map>
//this is bad practice I know, but It's here just for convenience
using namespace std;

int main(void)
{
	
	Trie<string> trie;
	cout << "empty?-"<< trie.empty() << "\n";
	cout << "word- meat\n";
	trie.insert("meat");
	cout << "empty?-"<< trie.empty() << "\n";
	cout << "add meap\n";
	trie.insert("meap");
	cout << "add meape\n";
	trie.insert("meape");
	cout << "size (should be 3)- "<< trie.size() << "\n"; 
	trie.erase("meap");
	cout << "size (should be 2)- "<< trie.size() << "\n"; 
	cout << "finding meape (should be true)" << trie["meap"] << "\n";
	
	/*
	string dinner = "dinner";
	cout << "word- dinner\n";
	bool has_dinner = trie.lookup(dinner);
	cout << has_dinner << "\n";
	has_dinner = trie.lookup(dinner);
	cout << has_dinner << "\n";
	*/

	cout << "testing over\n";
	return 0;
}
