#ifndef _DFA_NODE_H
#define _DFA_NODE_H

#include"DFA_EDGE.h"
#include<set>

using namespace std;

class DFA_NODE
{
public:
	int num;
	//dfa����Ӧ��nfa���
	set<int> nodes;	
	//��һ�����
	DFA_NODE *next;
	//�˽����ڱ�
	DFA_EDGE *edges;		
	//�Ƿ��ǽ���״̬
	bool accepet;
	DFA_NODE(int num,set<int> nodes):num(num),nodes(nodes)
	{
		next = nullptr;
		edges = nullptr;
		accepet = false;
	}
};

#endif