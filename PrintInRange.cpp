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
void printFloorNCeiling(node *root,int k1,int k2)
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
        if(s.top()->data>=k1 and s.top()->data<=k2)
            cout<<s.top()->data<<"   ";
        if(k2<s.top()->data)
            break;    
        root=s.top();s.pop();
        root=root->rc;
    }
    cout<<endl;
}
int main()
{
    node *root=NULL;
    root=insert(root,14);
    NRinorder(root);
    root=insert(root,6);
    NRinorder(root);
    root=insert(root,1);
    NRinorder(root);
    root=insert(root,13);
    NRinorder(root);
    root=insert(root,27);
    NRinorder(root);
    root=insert(root,38);
    NRinorder(root);
    root=insert(root,19);
    NRinorder(root);
    root=insert(root,15);
    NRinorder(root);
    int key=0,key2=0;
    cin>>key;
    cin>>key2;
    cout<<"\n";
    printFloorNCeiling(root,key,key2);
    return 0;
}