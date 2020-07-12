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
int findMax(node *root)
{
    if(root==NULL)
        return 0;
    while(root->rc!=NULL)
        root=root->rc;
    return root->data;
}
int findMin(node *root)
{
    if(root==NULL)
        return 0;
    while(root->rc!=NULL)
        root=root->lc;
    return root->data;
}
bool checkBST(node *root)
{
    if(!root)
        return true;
    if(root->lc and findMax(root->lc)>root->data)
        return false;
    if(root->rc and findMin(root->rc)<root->data)
        return false;
    if(!checkBST(root->lc) || !checkBST(root->rc))
        return false;
    return true;
}

int main()
{
    node *root=NULL;
    {
    root=insert(root,4);
    NRinorder(root);
    root=insert(root,2);
    NRinorder(root);
    root=insert(root,1);
    NRinorder(root);
    root=insert(root,3);
    NRinorder(root);
    root=insert(root,7);
    NRinorder(root);
    root=insert(root,8);
    NRinorder(root);
    root=insert(root,6);
    NRinorder(root);
    root=insert(root,5);
    NRinorder(root);
    }
    cout<<checkBST(root)<<endl;
    root->lc->lc->data=25;
    NRinorder(root);
    cout<<checkBST(root);
    cout<<endl;
    return 0;
}