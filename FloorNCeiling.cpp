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
void printFloorNCeiling(node *root,int key)
{

    if(!root)
        return;
    stack<node*> s;
    int prev=-1;
    int floor=-1,ceiling=-1;
    while (1)
    {
        while (root)
        {
            s.push(root);
            root=root->lc;
        }
        if(s.empty())
            break;
        //cout<<s.top()->data<<"   ";
        if(key<s.top()->data)
        {
            floor=prev;
            ceiling=s.top()->data;
            break;
        }
        prev=s.top()->data;
        root=s.top();s.pop();
        root=root->rc;
    }
    if(ceiling==-1)
    {
        cout<<"floor is: "<<prev<<" and ceiling does not exists\n";
        return;
    }
    if(floor==-1)
    {
        cout<<"floor does not exists and ceiling is: "<<ceiling<<endl;
        return;
    }
    cout<<"floor is: "<<floor<<" and ceiling is: "<<ceiling;
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
    int key=0;
    cin>>key;
    cout<<"\n";
    printFloorNCeiling(root,key);
    return 0;
}