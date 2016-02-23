#ifndef _DFA_H
#define _DFA_H

#include"NFA.h"
#include"DFA_NODE.h"
#include"DFA_EDGE.h"
class DFA
{	
	//查找序号为num的节点是否存在，如果不存在则创建结点并返回
	DFA_NODE *DFA_lookupOrInsert(set<int> num);
	//添加边
	void addEdge(set<int> from,set<int> to,char c);	
public:
	//nfa对象
	Nfa nfa;
	DFA_NODE *head;
	//是否需要添加新节点
	bool needNewNode;
	//结点的数目
	int nodeNumber;
	//将结点存储在数组里
	vector<DFA_NODE *> node;
	DFA(string exp);
	~DFA();
	//nfa转换为dfa
	void Nfa_toDFA();
	//子集构造算法,工作表算法
	void subsetConstruct();
	//寻找eps闭包
	set<int> eps_closure(set<int> X);
	//状态转换函数
	set<int> delta(set<int> q,char c);
	//将dfa打印出来
	void dfa_print();
	//将结点存在数组里
	void storePoint();

};

#endif


