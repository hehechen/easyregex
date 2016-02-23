#ifndef _RE_H
#define _RE_H

#include<iostream>
#include"DFA.h"
using namespace std;
class Re
{
	//��ǰ����ƥ����ַ�
	//Ҫƥ����ַ���
	string test_str;
	char curChar;
	//��ǰ�ַ���λ��
	int pos;
	//�õ���һ���ַ�
	char nextChar();
	//ƥ��һ���ַ�x
	bool matchOneChar(int state,char ch);
	//�ع�
	void rollback();
public:	
	DFA dfa;
	//ƥ�䵽������ַ���
	string matchString;
	Re(string exp);
	//ƥ���ַ���
	bool match(string str);
	//�ƥ��
	bool search(string str);

};

#endif