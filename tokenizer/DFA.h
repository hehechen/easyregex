#ifndef _DFA_H
#define _DFA_H

#include"NFA.h"
#include"DFA_NODE.h"
#include"DFA_EDGE.h"
class DFA
{	
	//�������Ϊnum�Ľڵ��Ƿ���ڣ�����������򴴽���㲢����
	DFA_NODE *DFA_lookupOrInsert(set<int> num);
	//��ӱ�
	void addEdge(set<int> from,set<int> to,char c);	
public:
	//nfa����
	Nfa nfa;
	DFA_NODE *head;
	//�Ƿ���Ҫ����½ڵ�
	bool needNewNode;
	//������Ŀ
	int nodeNumber;
	//�����洢��������
	vector<DFA_NODE *> node;
	DFA(string exp);
	~DFA();
	//nfaת��Ϊdfa
	void Nfa_toDFA();
	//�Ӽ������㷨,�������㷨
	void subsetConstruct();
	//Ѱ��eps�հ�
	set<int> eps_closure(set<int> X);
	//״̬ת������
	set<int> delta(set<int> q,char c);
	//��dfa��ӡ����
	void dfa_print();
	//��������������
	void storePoint();

};

#endif


