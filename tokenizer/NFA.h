#ifndef _NFA_H
#define _NFA_H

#include"NFA_EDGE.h"
#include"NFA_NODE.h"
#include"ReTree.h"
#include<vector>

using namespace std;

class Nfa
{
	NFA_NODE *head;
	//查找序号为num的节点是否存在，如果不存在则创建结点并返回
	NFA_NODE *Nfa_lookupOrInsert(int num);
public:
	//开始状态和接受状态
	int start,accept;	
	//结点数目
	int nodeNumber;
	//正则表达式树的对象
	ReTree tree;
	//将结点存储在数组里
	vector<NFA_NODE *> node;
	//将正则表达式树转化为nfa
	void Re_toNFA(ReTreeNode *root);
	//将结点存进数组
	void storePoint();
	//打印nfa
	void NFA_print();
	void addEdge(int from,int to,char c);		
	Nfa(string exp):tree(exp)
	{
		head = new NFA_NODE(0);
		start = 0;
		accept = 0;
		nodeNumber = 1;
		Re_toNFA(tree.root);
		storePoint();
	}

};

#endif