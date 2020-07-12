#include<bits/stdc++.h>
using namespace std;
class TreeNode
{
    public:
    int data;
    TreeNode *lc=nullptr;
    TreeNode *rc=nullptr;
    TreeNode(int d)
    {
        data=d;
    }
};
///////////////////Traversals///////////////////
void preorder(TreeNode *root)
{
    if(root)
    {
        cout<<root->data<<" ";
        preorder(root->lc);
        preorder(root->rc);
    }
}
//'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''//
stack<TreeNode*> preorderSuccessor(TreeNode *root)
{
    stack<TreeNode*> s1;
    stack<TreeNode*> s;
    while(1)
    {
        while(root)
        {
            cout<<root->data<<" ";
            s1.push(root);
            s.push(root);
            root=root->lc;
        }
        if(s.empty())
            break;
        root=s.top();
        s.pop();
        root=root->rc;
    }
    return s1;
}
void findPreorderSuccessor(stack<TreeNode*> s1,int node)
{
    int x,prev=-1;
    while(!s1.empty())
    {
        x=s1.top()->data;
        if(x==node)
            break;
        prev=x;
        s1.pop();    
    }
    cout<<"successor of "<<node<<" is "<<prev;
}
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''//
void NRPreorder(TreeNode *root)
{
    stack<TreeNode*> s;
    int max=INT32_MIN;
    while(1)
    {
        while(root)
        {
            cout<<root->data<<" ";
            if(root->data>=max)
            {
                max=root->data;
            }
            s.push(root);
            root=root->lc;
        }
        if(s.empty())
            break;
        root=s.top();
        s.pop();
        root=root->rc;
    }
    cout<<"\t"<<"Max val is:="<<max;
    cout<<endl;
}
void inorder(TreeNode *root)
{
    if(root)
    {
        inorder(root->lc);
        cout<<root->data<<" ";
        inorder(root->rc);
    }
}
void NRinorder(TreeNode *root)
{   
    stack<TreeNode*> s;
    while(1)
    {
        while(root)
        {
            s.push(root);
            root=root->lc;
        }
        if(s.empty())
        break;
        root=s.top();
        s.pop();
        cout<<root->data<<" ";
        root=root->rc;
    }
    cout<<endl;
}
void postorder(TreeNode *root)
{
    if(root)
    {
        postorder(root->lc);
        postorder(root->rc);
        cout<<root->data<<" ";
    }
}
void NRPostorder(TreeNode *root)
{   
    stack<TreeNode*> s;
    TreeNode *prev=NULL;
    do
    {
        while(root)
        {
            s.push(root);
            root=root->lc;
        }
        while(root==NULL and !s.empty())
        {
            root=s.top();
            if(root->rc==NULL or root->rc == prev)
            {
                cout<<root->data<<" ";
                s.pop();
                prev=root;
                root=NULL;
            }
            else    root=root->rc;
         }
    }while((!s.empty()));
    cout<<endl;
}
void levelorder(TreeNode *root)
{
    TreeNode *tmp;
    queue<TreeNode*> q;
    if(!root)
    return;
    q.push(root);
    while(!q.empty())
    {
        tmp=q.front();
        q.pop();
        cout<<tmp->data<<" ";
        if(tmp->lc)
        q.push(tmp->lc);
        if(tmp->rc)
        q.push(tmp->rc);

    }
    cout<<endl;
}
////////////////////////////////////////////////
TreeNode *createNode(int x)
{
    TreeNode *root=new TreeNode(x);
    return root;
}
int main()
{
    TreeNode *root=new TreeNode(1);
    TreeNode *tmp=createNode(2);
    root->lc=tmp;
    tmp=createNode(3);
    root->rc=tmp;
    tmp=createNode(4);
    root->lc->lc=tmp;
    tmp=createNode(5);
    root->lc->rc=tmp;
    tmp=createNode(666);
    root->rc->lc=tmp;
    tmp=createNode(7);
    root->rc->rc=tmp;
    inorder(root);
    cout<<endl;
    NRinorder(root);
    preorder(root);
    cout<<endl;
    stack<TreeNode*> s1=preorderSuccessor(root);
    cout<<endl<<"STACK CONTENTS";
    /*while(!s1.empty())
    {
       cout<<s1.top()->data<<"   ";
        s1.pop();
    }*/

    findPreorderSuccessor(s1,7);
    cout<<endl;
    NRPreorder(root);
    postorder(root);
    cout<<endl;
    NRPostorder(root);
    levelorder(root);
    return 0;
}