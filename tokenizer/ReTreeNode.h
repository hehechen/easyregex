#ifndef _RE_TREE_NODE_H
#define _RE_TREE_NODE_H

//ÿ���ڵ�������״̬��
//���� CONCAT
//ѡ�� ALT
//�հ� CLOSURE
//Ԫ�� ELEMENT
enum nodeType
	{
	  RE_KIND_EPS,
	  RE_KIND_CHAR,
	  RE_KIND_CONCAT,
	  RE_KIND_ALT,
	  RE_KIND_CLOSURE
	};
class ReTreeNode
{	
public:
	ReTreeNode *childNode[2];	//��������ӽڵ�
	char ch;					//������ַ�
	nodeType type;
	ReTreeNode(nodeType type,char ch,ReTreeNode *child_L,ReTreeNode *child_R):ch(ch),type(type)
	{
		childNode[0] = child_L;
		childNode[1] = child_R;		
	}
};

#endif