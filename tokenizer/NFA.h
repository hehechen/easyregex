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
	//�������Ϊnum�Ľڵ��Ƿ���ڣ�����������򴴽���㲢����
	NFA_NODE *Nfa_lookupOrInsert(int num);
public:
	//��ʼ״̬�ͽ���״̬
	int start,accept;	
	//�����Ŀ
	int nodeNumber;
	//������ʽ���Ķ���
	ReTree tree;
	//�����洢��������
	vector<NFA_NODE *> node;
	//��������ʽ��ת��Ϊnfa
	void Re_toNFA(ReTreeNode *root);
	//�����������
	void storePoint();
	//��ӡnfa
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