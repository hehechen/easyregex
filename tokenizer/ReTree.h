#ifndef _RE_TREE_H
#define _RE_TREE_H

#include<iostream>
#include"ReTreeNode.h"
#include<set>

using namespace std;

//正则表达式树
//基本正则表达式的bnf
	/*
	exp -> exp|A
	exp -> A
	  A -> A + B
	    -> A
	  B -> C*
	    -> C
	  C -> (exp)
		-> e
	*/
class ReTree
{
	//输入的表达式
	string exp;
	
	//当前正在解析的字符
	char curToken;
	//当前字符在exp中的位置
	int pos;
	//获取下一个字符
	char getNextToken();
public:
	//存储正则表达式中的字符
	set<char> set_Character;
	ReTree(string str);
	~ReTree();
	//表达式树的根节点
	ReTreeNode *root;
	//将正则表达式解析为表达式树
	void toReTree();
	//用递归下降法解析
	ReTreeNode *paraseEXP();
	ReTreeNode *paraseA();
	ReTreeNode *paraseB();
	ReTreeNode *paraseC();
	//将树打印出来，方便测试
	void printTree(ReTreeNode *tree);
};

#endif