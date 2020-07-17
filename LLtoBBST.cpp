#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class node
{
	public:
	int v;
	node *next=NULL;
};
class TreeNode
{
	public:
	int data;
	TreeNode *lc,*rc;
    TreeNode(int d)
    {
        data=d;
        node *lc=NULL;  
        node *rc=NULL;
    }
};
//Utility for list printing
void printll(node *head)
{
	node *ptr=head;
	if(head==NULL)
	cout<<"Empty List\n";
	while(ptr!=NULL)
	{
		cout<<ptr->v<<"-";
		ptr=ptr->next;
	}
	cout<<"X";
}
//Utility for Node creation
node * createNode(int x)
{
	node *p=new node();
	p->v=x;
	p->next=NULL;
	return p;
}
//...........Insertion Methods.........//
node *insertBeg(node *start,int x)
{
	node *ptr=createNode(x);
	if (start==NULL)
	{
		start=ptr;
		return start;
	}
	ptr->next=start;
	start=ptr;
	return start;
}
void NRinorder(TreeNode *root)
{
    if(!root)
        return;
    stack<TreeNode*> s;
    while (1)
    {
        while (root)
        {
            s.push(root);
            root=root->lc;
        }
        if(s.empty())
            break;
        cout<<s.top()->data<<"   ";
        root=s.top();s.pop();
        root=root->rc;
    }
    cout<<endl;
}
TreeNode *buildBBST(node *root,int start,int end)
{
    if(start>end)
        return NULL;
    int mid=start+ (end-start)/2;
    TreeNode *l=buildBBST(root,start,mid-1);
    TreeNode *parent=new TreeNode(root->v);
    parent->lc=l;
    root=root->next;
    parent->rc=buildBBST(root,mid+1,end);
    return parent;
}
int main()
{
  	node *start=NULL;
    for (int i=10;i >=1;i--)
        start=insertBeg(start,i);
	printll(start);
    TreeNode *root=buildBBST(start,0,9);
    NRinorder(root);
	cout<<endl;	
    return 0;
}