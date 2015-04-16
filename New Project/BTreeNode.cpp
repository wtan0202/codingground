#include "BTreeNode.h"
#include <iostream>
int BTreeNode::getKey(int index)
{
	return keys[index];
}
void BTreeNode::setKey(int index, int key)
{
	this->keys[index] = key;

}
int BTreeNode::getKeySize()
{
	return keysize;
}
void BTreeNode::setKeySize(int size)
{
	keysize = size;
}
int BTreeNode::getChildSize()
{
	return childSize;
}
void BTreeNode::setChildSize(int size)
{
	childSize = size;
}
IBTreeNode * BTreeNode::getChild(int index)
{
	return Children[index];
}
void BTreeNode::setChild(int index, IBTreeNode * child)
{
	Children[index] = (BTreeNode *)child;
}
bool BTreeNode::isLeaf()
{
	if (childSize > 0)
	{
		leaf = false;
	}
	else
	{
		leaf = true;
	}
	return leaf;
}

BTreeNode::BTreeNode()
{
	// Copy the given minimum degree and leaf property
	MinDegree = 3;
	leaf = true;

	// Allocate memory for maximum number of possible keys
	// and child pointers
	keys.resize(5);
	Children = new BTreeNode *[6];
	childSize = 0;
	// Initialize the number of keys as 0
	keysize = 0;
}