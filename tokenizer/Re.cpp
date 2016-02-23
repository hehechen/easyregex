#include"Re.h"
#include<stack>

using namespace std;

Re::Re(string exp):dfa(exp)
{
	pos = 0;
}

bool Re::matchOneChar(int state,char ch)
{
	if (dfa.node[state]->accepet == true && curChar == '\0')
	{
		return true;
	}
	DFA_EDGE *edge = dfa.node[state]->edges;
	while (edge != nullptr)
	{
		if (edge->ch == curChar)
		{
			curChar = nextChar();
			state = edge->to->num;
			//递归匹配
			if(matchOneChar(state,curChar))
				return true;
			else 
				return false;
		}
		edge = edge->next;
	}
	if (edge == nullptr)
	{
		return false;
	}
}
bool Re::match(string str)
{
	bool isMatched;
	test_str = str;
	curChar = nextChar();
	int state = 0;
	return matchOneChar(state,curChar);
}

char Re::nextChar()
{
	return test_str[pos++];
}

bool Re::search(string str)
{
	int state = 0;
	stack<int> stk;
	stk.push(-1);
	test_str = str;
	pos = 0;
	DFA_EDGE *edge = dfa.node[state]->edges;
s:
	curChar = nextChar();
	matchString += curChar;
	edge = dfa.node[state]->edges;
	if (dfa.node[state]->accepet)
	{//清空栈		
		while(!stk.empty())	
			stk.pop();
		stk.push(-1);
	}
	stk.push(state);
	while (edge != nullptr)
	{
		if (edge->ch == curChar)
		{
			state = edge->to->num;
			goto s;
		}
		edge = edge->next;
	}
	//如果接受状态没有后续结点，为了下面的代码仍然正确，添加这段翔一样的代码
	//if(curChar!='\0' && edge == nullptr && dfa.node[state]->accepet)
	//{
	//	curChar = nextChar();
	//	matchString += curChar;
	//	if (dfa.node[state]->accepet == true)
	//	{
	//		//清空栈
	//		while(stk.empty()==false)	stk.pop();
	//	}
	//	stk.push(state);
	//}


	if(pos)
	{
		while(state!=-1 && !dfa.node[state]->accepet)
		{
			stk.pop();
			state = stk.top();
			if(!matchString.empty())
				matchString.pop_back();
			rollback();
		}		
		if(state == -1)
		{
			if(curChar == '\0')
			{
				if(!matchString.empty())
					return true;
				else
					return false;
			}
			return false;
		}

		if(dfa.node[state]->accepet)
		{
			matchString.pop_back();
			if(!matchString.empty())
				return true;
		}
	}
	if(pos)
		return true;
	else 
		return false;
}

void Re::rollback()
{
	pos--;
}