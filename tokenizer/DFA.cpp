#include<iostream>
#include"DFA.h"
#include<queue>
using namespace std;

#define EPS -2

DFA::DFA(string exp):nfa(exp)
{
	head = nullptr;
	nodeNumber = 0;
	needNewNode = false;
	Nfa_toDFA();
	storePoint();
}

DFA::~DFA()
{
	delete head;
}

DFA_NODE *DFA::DFA_lookupOrInsert(set<int> num)
{
	DFA_NODE *tmp = head;
	while(tmp!=nullptr)
	{
		if(tmp->nodes == num)
			return tmp;
		tmp = tmp->next;
	}
	DFA_NODE *node = new DFA_NODE(nodeNumber,num);
	for(auto it = num.begin();it!=num.end();++it)
	{
		if(*it == nfa.accept)
			node->accepet = true;
	}
	nodeNumber++;
	node->next = head;
	needNewNode = true;
	head = node;
	return node;
}

void DFA::Nfa_toDFA()
{
	subsetConstruct();
}

void DFA::addEdge(set<int> from,set<int> to,char c)
{
	DFA_NODE *f = DFA_lookupOrInsert(from);
	DFA_NODE *t = DFA_lookupOrInsert(to);
	DFA_EDGE *edge = new DFA_EDGE(f,t,c,f->edges);
	f->edges = edge;
}

void DFA::subsetConstruct()
{
	int n0[1] = {0};
	queue<set<int>> Q;
	queue<set<int>> worklist;
	set<char> set_Character = nfa.tree.set_Character;
	set<int> sn0(n0,n0+1);
	set<int> q0 = eps_closure(sn0);
	Q.push(q0);
	worklist.push(q0);
	while(!worklist.empty())
	{
		set<int> q = worklist.front();
		worklist.pop();
		for(auto ch = set_Character.begin();ch !=set_Character.end();++ch)
		{
			set<int> t = eps_closure(delta(q,*ch));
			if(t.size() == 0)
				continue;
			addEdge(q, t, *ch);
			if(needNewNode)
			{
				Q.push(t);
				worklist.push(t);
				needNewNode = false;
			}
		}
	}

}
//宽度优先
set<int> DFA::eps_closure(set<int> X)
{
	set<int> closure;
	queue<int> Q;		//宽度优先所需的队列
	for(auto it = X.begin();it!=X.end();++it)
	{
		Q.push(*it);
		while(!Q.empty())
		{
			auto q = Q.front();
			closure.insert(q);
			Q.pop();
			for(auto y = nfa.node[q]->edges;y!=nullptr && y->ch == EPS;y = y->next)
			{
				Q.push(y->to->num);
				y->to->visited = true;
			}
		}
	}
	return closure;
}

set<int> DFA::delta(set<int> q,char c)
{
	set<int> nodes;
	for(auto it = q.begin();it!=q.end();++it)
	{
		for(NFA_EDGE *edge = nfa.node[*it]->edges;edge!=nullptr && edge->ch == c;edge = edge->next)
		{
			nodes.insert(edge->to->num);
		}
	}
	return nodes;
}
void DFA::dfa_print ()
{
	DFA_NODE *nodes = head;
	while (nodes){
		DFA_EDGE *edges = nodes->edges;
		while (edges){
			printf ("%d %d----(%c)----> %d  %d\n"
				, edges->from->num
				, edges->from->accepet
				, edges->ch
				, edges->to->num
				, edges->to->accepet);
			edges = edges->next;
		}
		nodes = nodes->next;
	}
	return;
}

void DFA::storePoint()
{
	node.resize(nodeNumber);
	for (DFA_NODE *p = head; p != nullptr; p = p->next)
	{
		node[p->num] = p;
	}
}