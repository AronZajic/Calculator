#pragma once
#include <string>
#include <vector>
#include <deque>

using namespace std;

class AA {

private:

	class Node {

	public:

		string key;
		string value;
		Node *next;

		Node(string key, string value, Node *next)
		{

			this->key = key;
			this->value = value;
			this->next = next;

		}
	};

	vector <Node*> table;
	deque <Node> nodes;

	int hash(string &key)
	{

		int i = 0;

		for (int f = 0; f < key.size(); f++)
			i += key.at(f);

		return i % table.size();

	}

public:

	AA(int size)
	{

		for (int f = 0; f < size; f++)
		{

			table.push_back(nullptr);

		}

	}

	void add(Node &node)
	{

		Node **tmp = &table[hash(node.key)];

		while (*tmp != nullptr)
			tmp = &(*tmp)->next;

		*tmp = &node;

	}

	void add(string &key, string &value)
	{
		if (nodes.size() > 0.9 * table.size())
		{
			table = vector <Node*>();

			for (int i = 0; i < 2 * nodes.size(); i++)
			{
				table.push_back(nullptr);
			}

			for (int i = 0; i < nodes.size(); i++)
			{
				nodes[i].next = nullptr;
				add(nodes[i]);
			}
		}

		Node **tmp = &table[hash(key)];

		while (*tmp != nullptr && (*tmp)->key != key)
			tmp = &(*tmp)->next;

		if (*tmp == nullptr)
		{
			nodes.push_back(Node(key, value, nullptr));
			*tmp = &nodes.back();
		}
		else
			(*tmp)->value = value;

	}

	string at(string &key)
	{

		Node **tmp = &table[hash(key)];

		while (*tmp != nullptr && (*tmp)->key != key)
			tmp = &(*tmp)->next;

		if(*tmp == nullptr)
			throw std::runtime_error(key + " is undefined!");

		return (*tmp)->value;

	}

};

AA associativeArray = AA(5);