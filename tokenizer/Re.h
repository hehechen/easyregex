#ifndef _RE_H
#define _RE_H

#include<iostream>
#include"DFA.h"
using namespace std;
class Re
{
	//当前正在匹配的字符
	//要匹配的字符串
	string test_str;
	char curChar;
	//当前字符的位置
	int pos;
	//得到下一个字符
	char nextChar();
	//匹配一个字符x
	bool matchOneChar(int state,char ch);
	//回滚
	void rollback();
public:	
	DFA dfa;
	//匹配到的最大字符串
	string matchString;
	Re(string exp);
	//匹配字符串
	bool match(string str);
	//最长匹配
	bool search(string str);

};

#endif