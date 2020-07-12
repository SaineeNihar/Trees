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
node *findMax(node *root)
{
    if(root==NULL)
        return NULL;
    while(root->rc!=NULL)
        root=root->rc;
    return root;
}
node *lca(node *root, int n1, int n2) 
{ 
    if (root == NULL) return NULL; 
    if (root->data > n1 && root->data > n2) 
        return lca(root->lc, n1, n2); 
    // If both n1 and n2 are greater than root, then LCA lies in right 
    if (root->data < n1 && root->data < n2) 
        return lca(root->rc, n1, n2); 
    return root; 
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
    cout<<lca(root,2,8)->data<<endl;
    return 0;
}