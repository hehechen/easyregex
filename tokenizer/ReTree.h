#ifndef _RE_TREE_H
#define _RE_TREE_H

#include<iostream>
#include"ReTreeNode.h"
#include<set>

using namespace std;

//������ʽ��
//����������ʽ��bnf
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
	//����ı��ʽ
	string exp;
	
	//��ǰ���ڽ������ַ�
	char curToken;
	//��ǰ�ַ���exp�е�λ��
	int pos;
	//��ȡ��һ���ַ�
	char getNextToken();
public:
	//�洢������ʽ�е��ַ�
	set<char> set_Character;
	ReTree(string str);
	~ReTree();
	//���ʽ���ĸ��ڵ�
	ReTreeNode *root;
	//��������ʽ����Ϊ���ʽ��
	void toReTree();
	//�õݹ��½�������
	ReTreeNode *paraseEXP();
	ReTreeNode *paraseA();
	ReTreeNode *paraseB();
	ReTreeNode *paraseC();
	//������ӡ�������������
	void printTree(ReTreeNode *tree);
};

#endif