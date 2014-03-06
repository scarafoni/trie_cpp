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

	//node class
	class Trie_Node
	{
	private:
		std::map<char,Trie_Node*> children;
	public:
		T  data;
		bool is_end;
		//default constructor
		Trie_Node(){}
		//destructor
		~Trie_Node(){clear_node();}
		//check if empty
		bool empty_node(){return children.empty();}

		//lookup child
		bool lookup_child(char index, std::string data)
		{
			//current letter
			char cl = data[index];

			//if we're at the end, return
			if(index == data.length())
			{
				if(is_end)
				{
					return true;
				}
				else
				{
					is_end = true;
					return false;
				}
			}
			//if the node below us is null, then it's not in the system
			else
			{
				if(children.find(cl) == children.end())
					return false;
	
				return children[cl]->lookup_child(index+1,data);
			}
		}
		bool insert_node(char index, std::string data)
		{
			//current letter
			char cl = data[index];

			//if we're at the end, return
			if(index == data.length()-1)
			{
				if(is_end)
				{
					return true;
				}
				else
				{
					std::cout << "end, word inserted- "<<data<<"\n";
					is_end = true;
					return false;
				}
			}
			//if the node below us is null, make it
			else
			{
				if(children.find(cl) == children.end())
				{
					children[cl] = new Trie_Node;	
				}
				return children[cl]->insert_node(index+1,data);
			}
		}

		bool erase_node(char index, std::string data)
		{
			//current letter
			char cl = data[index];

			//if we're at the end, return
			if(index == data.length())
			{
				is_end = false;
				return true;
			}
			//if the node below us is null, then it's not in the system
			else
			{
				if(children.find(cl) == children.end())
					return false;
	
				children[cl]->erase_node(index+1,data);
				if(children[cl]->empty_node() && !children[cl]->is_end)
					children[cl]->clear_node();
				return true;
			}
		}

		bool clear_node()
		{
			typedef typename std::map<char,Trie<T>::Trie_Node*>::iterator it;
			for(it iterator = children.begin(); iterator != children.end(); iterator++)
			{
				iterator->second->clear_node();
				delete iterator->second;
				children.erase(iterator);
			}
		}

		int size_node()
		{
			int counter = 0;
			if(is_end) counter++;

			typedef typename std::map<char,Trie<T>::Trie_Node*>::iterator it;
			for(it iterator = children.begin(); iterator != children.end(); iterator++)
				counter += iterator->second->size_node();
			return counter;
		}
	};

	Trie_Node* head_node;
	
public:
	//default constructor
	Trie()
	{head_node = new Trie_Node;}
	//copy constructor	
	Trie(Trie& other_trie)
		{head_node = other_trie.head_node;}
	//destructor
	~Trie()	{}


	//index overloader
	bool operator [] (std::string data){return head_node->lookup_child(0,data);}
	//insert a string
	bool insert(std::string data){return head_node->insert_node(0,data);}
	//erase a word
	bool erase(std::string data){return head_node->erase_node(0,data);}
	//delete the entire tree
	void clear(){head_node->clear_node();}
	//check if the trie is empty
	bool empty(){return head_node->empty_node();}
	//count the number of words in the array
	int size(){return head_node->size_node();}



};

#endif // __TRIE_H__
