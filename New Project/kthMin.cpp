#include "kthMin.h"
#include <stdlib.h>
void DoubleNode03::setValue(int value)
{
	m_Value = value;
}
int DoubleNode03::getValue()
{
	return m_Value;
}
IDoubleNode03 * DoubleNode03::getPrev()
{
	return m_Prev;
}
IDoubleNode03 * DoubleNode03::getNext()
{
	return m_Next;
}

void DoubleNode03::setPrev(IDoubleNode03 * prev)
{
	m_Prev = (DoubleNode03*)prev;
}
void DoubleNode03::setNext(IDoubleNode03 * next)
{
	m_Next = (DoubleNode03*)next;
}

DoubleList03::DoubleList03()
{
	m_Head = m_Tail = NULL;
	preNode = NULL;
	m_Root = NULL;
}
DoubleList03::~DoubleList03()
{
	for (DoubleNode03* p; m_Head != 0;)
	{
		p = (DoubleNode03*)m_Head->getNext();
		delete m_Head;
		m_Head = p;
	}
	m_Head = m_Tail = NULL;
}
IDoubleNode03 * DoubleList03::getHead()
{

	//print_tree(m_Root);
	return m_Head;
}
IDoubleNode03 * DoubleList03::getTail()
{
	return m_Tail;
}
void DoubleList03::setHead(IDoubleNode03 * head)
{
	m_Head = (DoubleNode03*)head;
}
void DoubleList03::setTail(IDoubleNode03 * tail)
{
	m_Tail = (DoubleNode03*)tail;
}
void DoubleList03::addBack(int value)
{
	insert_tree(m_Root, value);
}
void DoubleList03::setRoot(NODE* root)
{
	m_Root = root;
}

void DoubleList03::insert_tree(NODE *root, int num)   
{
	NODE *newnode = (NODE*)malloc(sizeof(NODE));  
	newnode->num = num;
	newnode->left = newnode->right = NULL;
	if (m_Root == NULL)
	{
		setRoot(newnode);
	}
	else
	{
		while (root) {                                          
			if (root->num == newnode->num)        
				break;
			if (root->num > newnode->num)          
				if (!root->left) {                      
				root->left = newnode;          
				return;
				}
				else
					root = root->left;              
			else                                                                                   
				if (!root->right) {
				root->right = newnode;
				return;
				}
				else
					root = root->right;
		}
		free(newnode);
	}
}
NODE* DoubleList03::getRoot()
{
	return m_Root;
}
int DoubleList03::size()
{
	return 0;
}


void DoubleList03::setPreNode(IDoubleNode03 * prenode)
{
	preNode = (DoubleNode03 *)prenode;
}

void DoubleList03::transferToList(NODE* root)
{
	if (m_Head == NULL&&root != NULL&&root->left == NULL)
	{
		DoubleNode03* node = new DoubleNode03();
		node->setValue(root->num);
		node->setPrev(NULL);
		node->setNext(NULL);
		setHead(node);
		setTail(node);
		setPreNode(node);
	}
	if (!root)
		return;
	transferToList(root->left);        
	if (root->num != m_Head->getValue())
	{
		DoubleNode03* newNode = new DoubleNode03();
		newNode->setValue(root->num);
		newNode->setPrev(preNode);
		newNode->setNext(NULL);
		preNode->setNext(newNode);
		setTail(newNode);
		setPreNode(newNode);
	}
	transferToList(root->right);
}