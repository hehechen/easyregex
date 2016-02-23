#include"DFA.h"
#include"Re.h"
#include<iostream>
#include<string>
using namespace std;

int main()
{
	Re *re = new Re("a(b*|c*)");
	re->dfa.dfa_print();
	cout<< re->search("abbbbbccac")<<re->matchString<<endl;
	return 0;
}