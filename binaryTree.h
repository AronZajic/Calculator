#pragma once
#include "treeNode.h"

class BinaryTree {

public:

	TreeNode *root;

	BinaryTree(const string &input)
	{

		int n = 0, i;

		string tmp = "";

		for (i = 0; i < input.length(); i++)
		{

			if (input.at(i) == '=')
				n++;

			if (input.at(i) != 32)
				tmp += input.at(i);

		}

		if (n == 1)
		{
			int pos = tmp.find('=', 1);

			string a = tmp.substr(0, pos);
			string b = tmp.substr(pos + 1, tmp.size() - pos - 1);

			if(isNumber(a))
				throw std::runtime_error("Cannot asign value to a number!");

			associativeArray.add(a, b);

			root = nullptr;

			return;

		}

		if(n > 1)
			throw std::runtime_error("Something is not right, please check your expression!");

		root = new TreeNode(tmp);

		root->solve();

		if(!isNumber(root->data))
			root = new TreeNode(associativeArray.at(root->data));

		root->solve();

	}

};