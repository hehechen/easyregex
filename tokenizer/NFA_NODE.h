#ifndef _NFANODE_H
#define _NFANODE_H

#include"NFA_EDGE.h"

class NFA_EDGE;
class NFA_NODE
{
	
public:
	int num;	//�˽ڵ�����
	NFA_EDGE *edges;	//�˽����ڱ�
	NFA_NODE *next;		//��һ�����
	//Ѱ�ұհ�ʱ�Ƿ��ѱ��ҹ�
	bool visited;
	NFA_NODE(int num):num(num)
	{
		edges = nullptr;
		next = nullptr;
		visited = false;
	}
};

#endif