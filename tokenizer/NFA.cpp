#include<iostream>
#include"NFA.h"
using namespace std;
#define EPS (-2)


NFA_NODE *Nfa::Nfa_lookupOrInsert(int num)
{
	NFA_NODE *tmp = head;
	while(tmp!=nullptr)
	{
		if(tmp->num == num)
			return tmp;
		tmp = tmp->next;
	}
	NFA_NODE *node = new NFA_NODE(num);
	nodeNumber++;
	this->node.push_back(node);
	node->next = head;
	head = node;
	return node;
}

void Nfa::addEdge(int from,int to,char ch)
{
	NFA_NODE *f = Nfa_lookupOrInsert(from);
	NFA_NODE *t = Nfa_lookupOrInsert(to);
	NFA_EDGE *edge = new NFA_EDGE(f,t,ch,f->edges);
	f->edges = edge;
}

int counter = 0;
int nextNum ()
{
	return counter++;
}

void Nfa::Re_toNFA(ReTreeNode *root)
{
	switch(root->type)
	{
	case RE_KIND_CHAR:
		{
			int from = nextNum();
			int to = nextNum();
			addEdge(from,to,root->ch);
			start = from;
			accept = to;
			break;
		}
	case RE_KIND_CONCAT:
		{
			Re_toNFA (root->childNode[0]);
			int oldStart = start;
			int oldAccept = accept;
			Re_toNFA (root->childNode[1]);
			addEdge(oldAccept,start,EPS);
			start = oldStart;
			break;
		}
	case RE_KIND_ALT:
		{
			int start = nextNum();
			int accept = nextNum();
			Re_toNFA (root->childNode[0]);
			addEdge(start,this->start,EPS);
			addEdge(this->accept,accept,EPS);
			Re_toNFA(root->childNode[1]);
			addEdge(start,this->start,EPS);
			addEdge(this->accept,accept,EPS);

			this->start = start;
			this->accept = accept;
			break;
		}
	case RE_KIND_CLOSURE:
		{
			int oldAccept = accept;
			int start = nextNum();
			int accept = nextNum();
			addEdge(start,accept,EPS);
			Re_toNFA(root->childNode[0]);
			addEdge(start,this->start,EPS);
			addEdge(this->accept,accept,EPS);
			addEdge(this->accept,this->start,EPS);

			this->start = start;
			this->accept = accept;
			break;
		}
	default:
		break;
	}
}

void Nfa::NFA_print ()
{
	NFA_NODE *nodes = head;
	while (nodes){
		NFA_EDGE *edges = nodes->edges;
		while (edges){
			printf ("%d ----(%d)----> %d\n"
				, edges->from->num
				, edges->ch
				, edges->to->num);
			edges = edges->next;
		}
		nodes = nodes->next;
	}
	return;
}

void Nfa::storePoint()
{
	node.resize(nodeNumber);
	for (NFA_NODE *p = head; p != nullptr; p = p->next)
	{
		node[p->num] = p;
	}
}