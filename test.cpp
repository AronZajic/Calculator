#include "pch.h"

#include <iostream>

#include "../Calculator/aa.h"
#include "../Calculator/binaryTree.h"

using namespace std;

TEST(AssociativeArrayTest) {

	AA aa = AA(1);

	aa.add(string("asd"), string("TestString"));

	aa.add(string("123"), string("TestString2"));

	aa.add(string("456"), string("TestString3"));

	EXPECT_EQ(aa.at(string("asd")), string("TestString"));
	EXPECT_EQ(aa.at(string("123")), string("TestString2"));
	EXPECT_EQ(aa.at(string("456")), string("TestString3"));

}

TEST(CalculationTest){

	BinaryTree *tree = new BinaryTree(string("((1+0))"));

	EXPECT_EQ(tree->root->data, to_string(1.0));

	tree = new BinaryTree(string("(1+0)"));

	EXPECT_EQ(tree->root->data, to_string(1.0));

	tree = new BinaryTree(string("1+0"));

	EXPECT_EQ(tree->root->data, to_string(1.0));

	tree = new BinaryTree(string("4+5*2"));

	EXPECT_EQ(tree->root->data, to_string(14.0));

	tree = new BinaryTree(string("5*(5+6*(9-7)/3)"));

	EXPECT_EQ(tree->root->data, to_string(45.0));

}