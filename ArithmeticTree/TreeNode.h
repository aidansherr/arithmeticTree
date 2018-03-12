#pragma once

#include <string>
#include <iostream>

class TreeNode
{
public:
	TreeNode();
	~TreeNode();

	TreeNode * getLeft();		
	TreeNode * getRight();	
	void setLeft(TreeNode *);	
	void setRight(TreeNode *);
	void setName(std::string);
	std::string getName();

private:
	TreeNode * leftNode;
	TreeNode * rightNode;
	std::string name;
};

