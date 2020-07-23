#include<bits/stdc++.h>
using namespace std;
using namespace std;
class Node
{
    public:
    int data,height;
    Node *lc,*rc;
    Node(int d)
    {
        data=d;
        lc=NULL;
        rc=NULL;
        height=1;
    }
};
void NRinorder(Node *root)
{
    if(!root)
        return;
    stack<Node*> s;
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
Node *buildHB0(int l,int r)
{
    int mid=l+((r-l)/2);
    if(l>r)
        return NULL;
    Node *node=new Node(mid);
    node->lc=buildHB0(l,mid-1);
    node->rc=buildHB0(mid+1,r);
    return node;
}
int main()
{
    int h;
    cin>>h;
    int nodes=pow(2,h+1)-1;
    Node *root=buildHB0(1,nodes);
    NRinorder(root);
    return 0;
}