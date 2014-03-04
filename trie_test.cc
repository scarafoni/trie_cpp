#include <iostream>
#include <string>
#include "trie.h"
#include <map>
//this is bad practice I know, but It's here just for convenience
using namespace std;

int main(void)
{
	Trie<string> starter;
	string meat = "meat";
	cout << "word- meat\n";
	bool has_meat = starter.add_node(meat);
	cout << has_meat << "\n";
	has_meat = starter.lookup(meat);
	cout << has_meat << "\n";

	string meap = "meap";
	cout << "word- meap\n";
	bool has_meap = starter.add_node(meap);
	cout << has_meap << "\n";
	cout << "lookup after add\n";
	has_meap = starter.lookup(meap);
	cout << has_meap << "\n";
	cout << "lookup after delete\n";
	starter.delete_node(meap);
	has_meap = starter.lookup(meap);
	cout << has_meap << "\n";

	/*
	string dinner = "dinner";
	cout << "word- dinner\n";
	bool has_dinner = starter.lookup(dinner);
	cout << has_dinner << "\n";
	has_dinner = starter.lookup(dinner);
	cout << has_dinner << "\n";
	*/

	cout << "testing over\n";
	return 0;
}
