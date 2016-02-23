#ifndef _DFA_EDGE_H
#define _DFA_EDGE_H


class DFA_NODE;
class DFA_EDGE
{
public:
	DFA_NODE *from;
	DFA_NODE *to;
	char ch;
	DFA_EDGE *next;
	DFA_EDGE(DFA_NODE *from,DFA_NODE *to,char ch,DFA_EDGE *next):from(from),to(to),ch(ch),next(next)	{}
};

#endif