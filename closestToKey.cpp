#include<bits/stdc++.h>
using namespace std;
class AVLNode
{
    public:
    int data,height;
    AVLNode *lc,*rc;
    AVLNode(int d)
    {
        data=d;
        lc=NULL;
        rc=NULL;
        height=1;
    }
};
int AVLheight(AVLNode *root)
{
    if(!root)
        return -1;
    return root->height; 
}
AVLNode *signleRR(AVLNode *node)
{
    AVLNode *tmp=node->lc;
    node->lc=tmp->rc;
    tmp->rc=node;
    node->height=max(AVLheight(node->lc),AVLheight(node->rc))+1;
    tmp->height=max(AVLheight(tmp->lc),node->height)+1;
    return tmp;
}
AVLNode *signleLR(AVLNode *node)
{
    AVLNode *tmp=node->rc;
    node->rc=tmp->lc;
    tmp->lc=node;
    node                                                                                                                                                                                                                                                                                                                                                                                                                                                                   ->height=max(AVLheight(node->lc),AVLheight(node->rc))+1;
    tmp->height=max(AVLheight(tmp->rc),node->height)+1;
    return tmp;
}
int getBalance(AVLNode *node)
{
    if(!node)
        return 0;
    return AVLheight(node->lc)-AVLheight(node->rc);
}
AVLNode *insert(AVLNode *node, int x)
{
    if(!node)
        return new AVLNode(x);
    if(x<node->data)
        node->lc=insert(node->lc,x);
    else if(x>node->data)
        node->rc=insert(node->rc,x);
    else 
        return node;
    node->height=max(AVLheight(node->lc),AVLheight(node->rc))+1;
    int bal=getBalance(node);
    if(bal>1 and x<node->lc->data)
        return signleRR(node);
    if(bal<-1 and x>node->rc->data)
        return signleLR(node);
    if(bal>1 and x>node->lc->data)
    {
        node->lc=signleLR(node->lc);
        return signleRR(node);
    }
    if(bal<-1 and x<node->rc->data)
    {
        node->rc=signleRR(node->rc);
        return signleLR(node);
    }
    return node;
}
void NRinorder(AVLNode *root)
{
    if(!root)
        return;
    stack<AVLNode*> s;
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
void preOrder(AVLNode *root)  
{  
    if(root != NULL)  
    {  
        cout << root->data << " ";  
        preOrder(root->lc);  
        preOrder(root->rc);  
    }  
}
AVLNode *findClosest(AVLNode *root,int k)
{
    if(!root)
        return NULL;
    if(root->data==k)
        return root;
    if(k<root->data)
    {
        if(!root->lc)
            return root;
        AVLNode *tmp=findClosest(root->lc,k);
        return abs(tmp->data-k)>abs(root->data-k)?root:tmp;
    }
    else
    {
        if(!root->rc)
            return root;
        AVLNode *tmp=findClosest(root->rc,k);
        return abs(tmp->data-k)>abs(root->data-k)?root:tmp;
    }
    return NULL;
}
int main()
{
    AVLNode *root = NULL;  
    /* Constructing tree given in  
    the above figure */
    cout<<"hey1";
    root = insert(root, 10);  
    root = insert(root, 20);  
    root = insert(root, 30);  
    root = insert(root, 40);  
    root = insert(root, 50);  
    root = insert(root, 25);
    root = insert(root, 80);  
    root = insert(root, 23);
    root = insert(root, 60);  
    root = insert(root, 35);

    cout<<"hey2"; 
    NRinorder(root);    
    cout<<findClosest(root,45)->data<<endl;
    preOrder(root);
    cout<<endl;
    return 0;
}