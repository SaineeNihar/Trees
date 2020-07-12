#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    char data;
    node *lc,*rc,*sib;
    node(char x)
    {
        data=x;
        lc=nullptr;
        rc=nullptr;
        sib=nullptr;
    }    
};
void preorder(node *root)
{
    if(!root)
        return;
    cout<<root->data<<"    ";
    preorder(root->lc);
    preorder(root->rc);
}
node *buildTree(string s,int *i)
{
    cout<<"Hey";
    if(s.empty())
        return NULL;
    node *n=new node(s[*i]);
    if(s[*i]=='L')
        return n;
    if(*i!=s.length())
    {
    *i=*i+1;
    n->lc=buildTree(s,i);
    *i=*i+1;
    n->rc=buildTree(s,i);
    }
    return n;
}
node *sibling(node *root)
{
    if(!root)
        return nullptr;
    if(root->lc)
        root->lc->sib=root->rc;
    if(root->rc)
        root->rc->sib=(root->sib)?root->sib->lc:NULL;
    sibling(root->lc);
    sibling(root->rc);
}
void printsibling(node *root)
{
    if(!root)
        return;
    if(root->sib)
    {
        cout<<root->data<<"'s sibling is "<<root->sib->data<<endl;
    }
    if(root->lc)
        printsibling(root->lc);
    if(root->rc)
        printsibling(root->rc);
}
int main()
{
    string s="IILLILL";
    int a=0;
    node *root=buildTree(s,&a);
    cout<<"Hey";
    preorder(root);
    sibling(root);
    printsibling(root);
    cout<<"\n";
return 0;
}