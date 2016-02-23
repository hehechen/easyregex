#ifndef _RE_TREE_NODE_H
#define _RE_TREE_NODE_H

//每个节点有四种状态：
//连接 CONCAT
//选择 ALT
//闭包 CLOSURE
//元素 ELEMENT
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
	ReTreeNode *childNode[2];	//最多两个子节点
	char ch;					//输进的字符
	nodeType type;
	ReTreeNode(nodeType type,char ch,ReTreeNode *child_L,ReTreeNode *child_R):ch(ch),type(type)
	{
		childNode[0] = child_L;
		childNode[1] = child_R;		
	}
};

#endif