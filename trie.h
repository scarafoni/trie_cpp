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
		std::map<char,Trie_Node*> children;
	public:
		T  data;
		bool is_end;
		Trie_Node(){}
		bool lookup_child(char index, std::string data)
		{
			//current letter
			char cl = data[index];
			//std::cout << "is_end?- "<<is_end<<" end of string" << index << "\n";

			//if we're at the end, return
			if(index == data.length())
			{
				if(is_end)
				{
					std::cout << "end, word found- "<<data<<"\n";
					return true;
				}
				else
				{
					std::cout << "end, word not found - "<<data<<"\n";
					is_end = true;
					return false;
				}
			}
			//if the node below us is null, then it's not in the system
			else
			{
				if(children.find(cl) == children.end())
					return false;
	
				std::cout << "need to go deeper on- "<<cl<<"\n";
				return children[cl]->lookup_child(index+1,data);
			}
		}
		bool add_node(char index, std::string data)
		{
			//current letter
			char cl = data[index];
			//std::cout << "is_end?- "<<is_end<<" end of string" << index << "\n";

			//if we're at the end, return
			if(index == data.length())
			{
				if(is_end)
				{
					std::cout << "end, word found- "<<data<<"\n";
					return true;
				}
				else
				{
					std::cout << "end, word not found - "<<data<<"\n";
					is_end = true;
					return false;
				}
			}
			//if the node below us is null, make it
			else
			{
				if(children.find(cl) == children.end())
				{
					std::cout << "made a baby on- "<<cl<<"\n";
					children[cl] = new Trie_Node;	
				}
				std::cout << "need to go deeper on- "<<cl<<"\n";
				return children[cl]->add_node(index+1,data);
			}
		}

		bool delete_node(char index, std::string data)
		{
			//current letter
			char cl = data[index];

			//if we're at the end, return
			if(index == data.length())
			{
				if(is_end)
				{
					std::cout << "end, word found- "<<data<<"\n";
					return true;
				}
				else
				{
					std::cout << "end, word not found - "<<data<<"\n";
					is_end = true;
					return false;
				}
			}
			//if the node below us is null, then it's not in the system
			else
			{
				if(children.find(cl) == children.end())
					return false;
	
				std::cout << "need to go deeper on- "<<cl<<"\n";
				if(children[cl]->delete_node(index+1,data))
				{
					std::cout << "deleteing on-  "<<cl<<"\n";
					delete(children[cl]);
					children.erase(cl);
					return true;
				}
				return false;
			}
		}
	};

	Trie_Node* head_node;
	
public:
	bool lookup(std::string data)
		{return head_node->lookup_child(0,data);}
	bool add_node(std::string data)
		{return head_node->add_node(0,data);}
	bool delete_node(std::string data)
	{
		//if(lookup(data))
			return head_node->delete_node(0,data);
		//else
			//return false;
	}

	Trie()
	{
		head_node = new Trie_Node();
	}
};

#endif // __TRIE_H__
