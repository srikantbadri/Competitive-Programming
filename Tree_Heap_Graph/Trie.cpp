#include<iostream>
#include<string.h>
#include<cstdlib>
#define CHAR_TO_INDEX(c)     ((int)c-(int)'a')
using namespace std;
typedef struct Sub_Nodes s;
struct Sub_Nodes
{
	int value;
	s *children[26];
};
typedef struct Root_Node r;
struct Root_Node
{
	s *root;
	int count;
};
s *getnode()
{
	s *ptr=NULL;
	ptr=(s*)malloc(sizeof(s));
	if(ptr!=NULL)
	{
		int i;
		ptr->value=0;
		for(i=0;i<26;i++)     //26 alphabets.
		ptr->children[i]=NULL;
	}
	return ptr;
}
void insert(r *root_node,char keys[])
{
	int level;
	int length=strlen(keys);
	int index;
	root_node->count++;
	s *sub_node;
	sub_node=root_node->root;
	for(level=0;level<length;level++)
	{
		index=CHAR_TO_INDEX(keys[level]);
		if(!sub_node->children[index])
		{
			sub_node->children[index]=getnode();	
		}
		sub_node=sub_node->children[index];
	}
	//Mark last node as leaf.
	sub_node->value=root_node->count;	
}
int search(r* root_node,char keys[])
{
	int level;
	int height=strlen(keys);
	int index;
	s* sub_node;
	sub_node=root_node->root;
	for(level=0;level<height;level++)
	{
		index=CHAR_TO_INDEX(keys[level]);
		if(!sub_node->children[index])
		{
			return 1;
		}
		sub_node=sub_node->children[index];
	}
	if(sub_node!=NULL && sub_node->value!=0)
	return 0;
	else
	return 1;
}
void initialize(r *node)
{
	node->root=getnode();
	node->count=0;
}
int main()
{
	char keys[][8]={"the","a","there","answer","any","by","bye","their"};
	char output[][32]={"Present","Not Present"};
	r trie;
	int i;
	initialize(&trie);
	for(i=0;i<8;i++)
	{
		insert(&trie,keys[i]);
		cout<<i<<"Inserted\n";
	}
	cout<<"Insertion Completed\n";
	cout<<"Searching there.......\n"<<output[search(&trie,"there")];
	cout<<"\nSearching abcd......\n"<<output[search(&trie,"abcd")];
	return 0;
}
