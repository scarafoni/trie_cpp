#include <iostream>
#include <string>
#include "trie.h"
#include <map>
//this is bad practice I know, but It's here just for convenience
using namespace std;

int main(void)
{
	Trie<string> starter;
	std::map<char,int> mymap;
	mymap['c'] = 44;
	mymap['a'] = 22;

	if(mymap.find('a') != mymap.end())
		cout << mymap['a'] << "\n";
	else
		cout << "error" << "error\n";

	cout << "testing over\n";
	return 0;
}
