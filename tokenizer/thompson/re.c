#include <assert.h>
#include <stdio.h>
#include "new.h"
#include "re.h"
#include "todo.h"

#define EPS (-2)

Re_t Re_Eps_new ()
{
  Re_Eps_t p;
  NEW(p);
  p->kind = RE_KIND_EPS;
  return (Re_t)p;
}

Re_t Re_Char_new (int c)
{
  Re_Char_t p;
  NEW(p);
  p->kind = RE_KIND_CHAR;
  p->c = c;
  return (Re_t)p;
}

Re_t Re_Concat_new (Re_t left, Re_t right)
{
  Re_Concat_t p;
  NEW(p);
  p->kind = RE_KIND_CONCAT;
  p->left = left;
  p->right = right;
  return (Re_t)p;
}

Re_t Re_Alt_new (Re_t left, Re_t right)
{
  Re_Alt_t p;
  NEW(p);
  p->kind = RE_KIND_ALT;
  p->left = left;
  p->right = right;
  return (Re_t)p;
}

Re_t Re_Closure_new (Re_t exp)
{
  Re_Closure_t p;
  NEW(p);
  p->kind = RE_KIND_CLOSURE;
  p->exp = exp;
  return (Re_t)p;
}

void Re_print (Re_t e)
{
  assert (e);
  switch (e->kind){
  case RE_KIND_EPS:
    printf ("\\eps");
    break;
  case RE_KIND_CHAR:{
    Re_Char_t p = (Re_Char_t)e;
    printf ("%d", p->c);
    break;
  }
  case RE_KIND_ALT:{
    Re_Alt_t p = (Re_Alt_t)e;
    printf ("(");
    Re_print (p->left);
    printf (") | (");
    Re_print (p->right);
    printf (")");
    break;
  }
  case RE_KIND_CONCAT:{
    Re_Concat_t p = (Re_Concat_t)e;
    printf ("(");
    Re_print (p->left);
    printf (")(");
    Re_print (p->right);
    printf (")");
    break;
  }
  case RE_KIND_CLOSURE:{
    Re_Closure_t p = (Re_Closure_t)e;
    printf ("(");
    Re_print (p->exp);
    printf (")*");
    break;
  }
  default:
    break;
  }
  return;
}

static int counter = 0;
static int nextNum ()
{
  return counter++;
}

static Nfa_t Re_thompsonDoit (Nfa_t nfa,Re_t e)
{
  assert (e);
  switch (e->kind){
  case RE_KIND_EPS:{
    int from = nextNum();
    int to = nextNum();
    Nfa_addEdge (nfa, from, to, EPS);
    nfa->start = from;
    nfa->accept = to;
    break;
  }
  case RE_KIND_CHAR:{
    Re_Char_t p = (Re_Char_t)e;
    int from = nextNum();
    int to = nextNum();
    Nfa_addEdge (nfa, from, to, p->c);
    nfa->start = from;
    nfa->accept = to;
    break;
  }
  case RE_KIND_ALT:{
    TODO();
    break;
  }
  case RE_KIND_CONCAT:{
    Re_Concat_t p = (Re_Concat_t)e;
    Re_thompsonDoit (nfa, p->left);
    int oldStart = nfa->start;
    int oldAccept = nfa->accept;
    Re_thompsonDoit (nfa, p->right);
    Nfa_addEdge(nfa, oldAccept, nfa->start,
                EPS);
    nfa->start = oldStart;
    break;
  }
  case RE_KIND_CLOSURE:{
    TODO();
    break;
  }
  default:
    break;
  }
  return;
}

Nfa_t Re_thompson (Re_t e)
{
  Nfa_t nfa = Nfa_new ();
  counter = 0;
  Re_thompsonDoit (nfa, e);
  return nfa;
}
