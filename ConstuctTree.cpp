#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    char data;
    node *lc,*rc;
    node(char x)
    {
        data=x;
        lc=nullptr;
        rc=nullptr;
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
int main()
{
    string s="IILLILL";
    int a=0;
    node *root=buildTree(s,&a);
    cout<<"Hey";
    preorder(root);
    cout<<"\n";
return 0;
}