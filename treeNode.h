#pragma once
#include "aa.h"

using namespace std;

bool isNumber(const string &input)
{
	int n = 0;

	for (int i = 0; i < input.size(); i++)
	{
		if (input.at(i) == '.')
			n++;

		if (!((input.at(i) > 47 && input.at(i) < 58) || input.at(i) == '.') || n > 1)
		{
			return false;
		}
	}
	return true;
}

class TreeNode {
public:

	string data;

	TreeNode* right = nullptr;
	TreeNode* left = nullptr;

	TreeNode(const string &input)
	{

		if (parse(input, '+', '-'))
			return;
		if (parse(input, '*', '/'))
			return;

		data = input;
	}

	void solve()
	{

		if (left == nullptr && right == nullptr)
			return;

		left->solve();
		right->solve();

		if (!isNumber(left->data))
			left = new TreeNode(associativeArray.at(left->data));

		if (!isNumber(right->data))
			right = new TreeNode(associativeArray.at(right->data));

		left->solve();
		right->solve();

		if (isNumber(left->data) && isNumber(right->data))
		{

			if (data == "*") data = to_string(stof(left->data) * stof(right->data));
			if (data == "/") data = to_string(stof(left->data) / stof(right->data));
			if (data == "+") data = to_string(stof(left->data) + stof(right->data));
			if (data == "-") data = to_string(stof(left->data) - stof(right->data));


			left = nullptr;
			right = nullptr;

			return;

		}

		throw std::runtime_error("Something is not right, please check your expression!");

	}

private:

	bool parse(const string &input, char a, char b)
	{

		bool h = true;
		int i = input.length();
		vector <char> brackets;

		if (input == "")
			throw std::runtime_error("Something is not right, please check your expression!");

		while (i > 0)
		{

			i--;

			if (input.at(i) == ')' || input.at(i) == ']' || input.at(i) == '}')
			{

				brackets.push_back(input.at(i));
				continue;

			}

			if (input.at(i) == '(' || input.at(i) == '[' || input.at(i) == '{')
			{

				if (brackets.size() > 0 && input.at(i) < brackets[brackets.size() - 1] && input.at(i) + 4 > brackets[brackets.size() - 1])
				{

					brackets.pop_back();
					continue;

				}

				throw std::runtime_error("Uncorrect brackets!");

			}

			if (brackets.size() == 0)
			{

				h = false;

				if ((input.at(i) == a || input.at(i) == b))
				{

					data = input.at(i);

					left = new TreeNode(input.substr(0, i));
					right = new TreeNode(input.substr((int)i + (int)1, (int)input.length() - (int)i));

					return true;

				}

			}

		}

		i = input.length() - 1;

		if ((input.at(i) == ')' || input.at(i) == ']' || input.at(i) == '}') &&
			(input.at(0) == '(' || input.at(0) == '[' || input.at(0) == '{') &&
			(input.at(0) < input.at(i) && input.at(0) + 4 > input.at(i)) &&
			h)
		{

			return parse(input.substr(1, i - 1), a, b);

		}

		return false;

	}

};