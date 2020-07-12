#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
    char data;
    node *fc, *ns;
    node(char d)
    {
        data=d;
        fc=nullptr;
        ns=nullptr;
    }
};
node *makeTree()
{
    node *root=new node('A');
    root->fc=new node('B');
    root->fc->ns=new node('C');
    root->fc->ns->ns=new node('D');
    root->fc->ns->ns->fc=new node('H');
    root->fc->ns->ns->ns=new node('E');
    root->fc->ns->ns->ns->fc=new node('I');
    root->fc->ns->ns->ns->fc->ns=new node('J');
    root->fc->ns->ns->ns->fc->ns->ns=new node('P');
    root->fc->ns->ns->ns->fc->ns->ns->ns=new node('Q');
    root->fc->ns->ns->ns->ns=new node('F');
    root->fc->ns->ns->ns->ns->fc=new node('K');
    root->fc->ns->ns->ns->ns->fc->ns=new node('L');
    root->fc->ns->ns->ns->ns->fc->ns->ns=new node('M');
    root->fc->ns->ns->ns->ns->ns=new node('G');
    root->fc->ns->ns->ns->ns->ns->fc=new node('N');
    return root;
}
int main()
{
    node *root=makeTree();
    


    return 0;
}