#include<iostream>
#include<ctype.h>
#include"ReTree.h"


using namespace std;

ReTree::ReTree(string str)
{
	exp = str;
	pos = 0;
	curToken = str[0];
	root = paraseEXP();
}

ReTree::~ReTree()
{
	delete root;
}

ReTreeNode *ReTree::paraseEXP()
{
	ReTreeNode *node = paraseA();
	while(curToken == '|')
	{
		curToken = getNextToken();
		ReTreeNode *child = paraseA();
		ReTreeNode *p = new ReTreeNode(RE_KIND_ALT,'|',node,child);
		node = p;
	}
	return node;
}

ReTreeNode *ReTree::paraseA()
{
	ReTreeNode *node = paraseB();
	if (curToken == '\0')
		return node;
	while(curToken == '(' || isalpha(curToken))
	{
		ReTreeNode *child = paraseB();
		ReTreeNode *p = new ReTreeNode(RE_KIND_CONCAT,'+',node,child);
		node = p;
	}
	return node;
}

ReTreeNode *ReTree::paraseB()
{
	ReTreeNode *node = paraseC();
	if (curToken == '\0')
		return node;
	if(curToken == '*')
	{
		ReTreeNode *p = new ReTreeNode(RE_KIND_CLOSURE,'*',node,nullptr);
		node = p;
		curToken = getNextToken();
	}
	return node;
}

ReTreeNode *ReTree::paraseC()
{
	ReTreeNode *p = nullptr;
	if(curToken == '(')
	{
		curToken = getNextToken();
		p = paraseEXP();
		curToken = getNextToken();
	}
	else
	{
		p = new ReTreeNode(RE_KIND_CHAR,curToken,nullptr,nullptr);
		curToken = getNextToken();
		set_Character.insert(p->ch);
	}
	return p;
}

void ReTree::printTree(ReTreeNode *tree)
{
	static int indentno = 0;
	indentno += 2;
	if (tree != nullptr)
	{
		for (int i = 0; i < indentno; i++)
			cout << " ";
		cout << tree->ch << endl;
		printTree(tree->childNode[0]);
		printTree(tree->childNode[1]);
	}
	indentno -= 2;
}

char ReTree::getNextToken()
{
	return exp[++pos];
}
