#ifndef _DFA_NODE_H
#define _DFA_NODE_H

#include"DFA_EDGE.h"
#include<set>

using namespace std;

class DFA_NODE
{
public:
	int num;
	//dfa结点对应的nfa结点
	set<int> nodes;	
	//下一个结点
	DFA_NODE *next;
	//此结点的邻边
	DFA_EDGE *edges;		
	//是否是接受状态
	bool accepet;
	DFA_NODE(int num,set<int> nodes):num(num),nodes(nodes)
	{
		next = nullptr;
		edges = nullptr;
		accepet = false;
	}
};

#endif