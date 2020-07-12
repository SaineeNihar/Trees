#include<bits/stdc++.h>
using namespace std;
int ind=0;
class node
{
    public:
        char data;
        vector<node*> child;
    node(char d)
    {
        data=d;
    }
};
node *buildTree(char preorder[],int n,int k,int height)
{
    if(n<=0)
        return nullptr;
    node *root=new node(preorder[ind]);
    cout<<"\n making chidren of "<<root->data<<"\t value of IND"<<ind<<endl;
    for(int i=0;i<k;i++)
    {   
        if(ind<n-1 && height>1)
        {
            ind++;
            root->child.push_back(buildTree(preorder,n,k,height-1));
        }
        else
        {
            root->child.push_back(NULL);
        }
    }
    return root;
}
void postord(node *root, int k) 
{ 
    if (root == NULL) 
        return; 
    for (int i = 0; i < k; i++) 
        postord(root->child[i], k); 
    cout << root->data<< " "; 
}
void PrintPreorder(node *root,int k)
{
    if(!root)
        return;
    cout<<root->data;
    for(int i=0;i<k;i++)
    {
        if(root->child[i])
        {
            PrintPreorder(root->child[i],k);
        }
    }
}
int main()
{
    char preorder[]={'A','B','E','F','G','C','I','J','K','D'};
    cout<<sizeof(preorder)<<endl;
    int height = (int)ceil(log((double)sizeof(preorder) * (3 - 1) + 1)/ log((double)3));
    node *root=buildTree(preorder,sizeof(preorder),3,height);
    postord(root,3);
    PrintPreorder(root,3);
    //cout<<endl<<root->child[1]->data<<endl;
    return 0;
}