#ifndef _NFANODE_H
#define _NFANODE_H

#include"NFA_EDGE.h"

class NFA_EDGE;
class NFA_NODE
{
	
public:
	int num;	//此节点的序号
	NFA_EDGE *edges;	//此结点的邻边
	NFA_NODE *next;		//下一个结点
	//寻找闭包时是否已被找过
	bool visited;
	NFA_NODE(int num):num(num)
	{
		edges = nullptr;
		next = nullptr;
		visited = false;
	}
};

#endif