#include <iostream>
#include <fstream>
#include <string>
#include "trie.h"
#include <map>
#include <locale>
#include <cctype>
#include <functional>
#include <algorithm>
//this is bad practice I know, but It's here just for convenience
using namespace std;

string removeSpaces(string input);

int main(void)
{
	ifstream dictionary_file ("dictionary.txt");
	string line;
	Trie<string> trie;
	int x = 0;
	if(dictionary_file.is_open())
	{
		while(getline (dictionary_file,line))
			cout << "attempte to insert "<<line<<"\n\t- "<< trie.insert(line)<<"\n";
	}
	
	cout << "size of trie- " << trie.size() <<"\n";
	cout <<"\n\nword eatery is here?- "<<trie["eatery"]<<"\n";
	trie.erase("eatery");
	cout <<"\n\nword eaterty is here after erasure?- "<<trie["eatery"]<<"\n";
	cout <<"\n\nsimilar word (eat) is here?- "<<trie["eat"]<<"\n";

	Trie<string> trie2(trie);
	cout <<"\n\nsize after clear- "<<trie2.size()<<"\n";


	cout << "testing over\n";
	return 0;
}
