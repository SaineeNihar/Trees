#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    int data;
    node *fc, *ns;
    node(int d)
    {
        data=d;
        fc=nullptr;
        ns=nullptr;
    }
};
node *makeTree()
{
    node *root=new node(1);
    root->fc=new node(2);
    root->fc->ns=new node(3);
    root->fc->ns->ns=new node(4);
    root->fc->ns->ns->fc=new node(8);
    root->fc->ns->ns->ns=new node(5);
    root->fc->ns->ns->ns->fc=new node(9);
    root->fc->ns->ns->ns->fc->ns=new node(10);
    root->fc->ns->ns->ns->fc->ns->ns=new node(15);
    root->fc->ns->ns->ns->fc->ns->ns->ns=new node(16);
    root->fc->ns->ns->ns->ns=new node(6);
    root->fc->ns->ns->ns->ns->fc=new node(11);
    root->fc->ns->ns->ns->ns->fc->ns=new node(12);
    root->fc->ns->ns->ns->ns->fc->ns->ns=new node(13);
    root->fc->ns->ns->ns->ns->ns=new node(7);
    root->fc->ns->ns->ns->ns->ns->fc=new node(14);
    return root;
}
int sumTheTree(node *root)
{
    if(!root)
        return 0;
    return root->data+sumTheTree(root->fc)+sumTheTree(root->ns);
}
int main()
{
    node *root=makeTree();
    cout<<sumTheTree(root)<<endl;
    return 0;
}