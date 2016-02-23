#ifndef _NFAEDGE_H
#define _NFAEDGE_H

#include"NFA_NODE.h"

class NFA_NODE;
class NFA_EDGE
{
public:
	NFA_NODE *from;
	NFA_NODE *to;
	char ch;
	NFA_EDGE *next;
	NFA_EDGE(NFA_NODE *from,NFA_NODE *to,char ch,NFA_EDGE *next):from(from),to(to),ch(ch),next(next)	{}

};

#endif