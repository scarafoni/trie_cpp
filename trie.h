#ifndef __TRIE_H__
#define __TRIE_H__
#include<stdio.h>
#include<iostream>
#include<string>
#include<map>

template <class T> 
class Trie
{
private:
	class Trie_Node
	{
	private:
		std::map<char,Trie_Node> children;
	public:
		T  data;
	};

	Trie_Node* head_node;
	
public:
	T get_head_data(){return head_node.data;}
};

#endif // __TRIE_H__
