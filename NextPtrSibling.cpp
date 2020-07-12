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
void siblings(node *root)
{
    if (root==nullptr)
        return;
    queue<node*> q;
    node *tmp;
    q.push(root);
    while(!q.empty())
    {
        tmp=q.front();
        if(!tmp)
            if(!q.empty())
                q.push(NULL);
        else
        {
            tmp->sib=q.front();
            if(tmp->lc)
                q.

        }
        
    }

}
int main()
{
    string s="IILLILL";
    int a=0;
    node *root=buildTree(s,&a);
    preorder(root);
    siblings(root);
    cout<<"\n";
return 0;
}