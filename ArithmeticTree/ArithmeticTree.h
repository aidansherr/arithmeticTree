#pragma once

#include <iostream>
#include <string>
#include <stack>
#include "TreeNode.h"

class ArithmeticTree
{
public:
	ArithmeticTree();
	~ArithmeticTree();
	void setValues();					// obtains values from user
	TreeNode * createTree();			// creates a tree from expression
	void traverseTree(TreeNode * tree);	// go through tree recursively to obtain expression
	void solveTree(TreeNode * tree);	// replace variables with input vals and evaluate expression
	void printValues();					// input values
	void printSolution();				// result from solveTree
	void printExpression();				// hard coded expression
	void printValExpr();				// expression with values in place

private:
	// input values
	int A;
	int B;
	int C;
	int D;

	std::string expression;				// hard coded expression
	std::string tmpexpr;				// temporary expression for entering input values
	std::string treeExpr;				// final expression with input values
	int solution;						// result from solveTree
	std::stack <TreeNode*> expr;		// stack to create tree
};

