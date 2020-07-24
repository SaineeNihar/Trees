#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int data;
    node *lc,*rc;
    node(int d)
    {
        data=d;
        lc=nullptr;
        rc=nullptr;
    }
};
node *insert(node *root,int x)
{
    if(!root)
        return new node(x);
    if(x<root->data)
        root->lc=insert(root->lc,x);
    else if(x>root->data)
        root->rc=insert(root->rc,x);
    return root;
}
void NRinorder(node *root)
{
    if(!root)
        return;
    stack<node*> s;
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
node *pruneBST(node *root,int x,int y)
{
    if(!root) return nullptr;
    root->lc=pruneBST(root->lc,x,y);
    root->rc=pruneBST(root->rc,x,y);
    if(root->data>=x and root->data<=y)
        return root;
    if(root->data<x)
        return root->rc;
    if(root->data>y)
        return root->lc;
}
int main()
{
    node *root=NULL;
    root=insert(root,40);
    NRinorder(root);
    root=insert(root,20);
    NRinorder(root);
    root=insert(root,10);
    NRinorder(root);
    root=insert(root,30);
    NRinorder(root);
    root=insert(root,70);
    NRinorder(root);
    root=insert(root,80);
    NRinorder(root);
    root=insert(root,60);
    NRinorder(root);
    root=insert(root,50);
    NRinorder(root);
    //find(root,11);
    root=pruneBST(root,20,50);
    NRinorder(root);
       return 0;
}