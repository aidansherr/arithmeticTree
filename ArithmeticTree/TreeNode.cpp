#include "TreeNode.h"

using namespace std;

TreeNode::TreeNode()
{
	leftNode = nullptr;
	rightNode = nullptr;
	name = "";
}


TreeNode::~TreeNode()
{
	delete leftNode;
	leftNode = nullptr;
	delete rightNode;
	rightNode = nullptr;
}

TreeNode * TreeNode::getLeft()
{
	return leftNode;
}

TreeNode * TreeNode::getRight()
{
	return rightNode;
}

void TreeNode::setLeft(TreeNode * node)
{
	leftNode = node;
}

void TreeNode::setRight(TreeNode * node)
{
	rightNode = node;
}

void TreeNode::setName(string n)
{
	name = n;
}

string TreeNode::getName()
{
	return name;
}


