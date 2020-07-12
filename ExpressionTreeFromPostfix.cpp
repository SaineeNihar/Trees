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
node *makeTree(char a[],int n)
{
    stack<node*> s;
    for(int i=0;i<n;i++)
    {
        if(a[i]!='/' && a[i]!='*' && a[i]!='+' && a[i]!='-' )
        {
            node *tmp=new node(a[i]);
            s.push(tmp);
        }
        else
        {
            node *s1=s.top();s.pop();
            node *s2=s.top();s.pop();
            node *root=new node(a[i]);
            root->lc=s2;root->rc=s1;
            s.push(root);
        }
    }
    return s.top();
}
int main()
{
    char a[]={'A','B','C','*','+','D','/'};
    node *root=makeTree(a,sizeof(a)/sizeof(a[0]));
    preorder(root);
    cout<<"\n";
    return 0;
}