#include<iostream>
using namespace std;
//#include<malloc.h>
#include<stdlib.h>
#include<stdio.h>
#include<queue>
int hash[100];
 
 
using namespace std;
 
typedef class tree
{
    public:
    int data;
     tree* left;
     tree* right;
     tree* parent;
     static tree* root;
     tree();
     virtual void addNode(tree* t,int data);
     static tree* createTree(int data);
     tree* newNode();
     void inorder(tree* t);
     void levelorder(tree* t);
     int heightOfTreeR(tree* t);
     int countNodesR(tree* t);
     int countLeavesR(tree* t);
     int max_path_length(tree* t, int max_path_l);
     int max_path_l;
}tree;
 
 
void Vsum(tree* t,int col)
{
if(!t)
 return;
Vsum(t->left,col-1);
hash[col]+=t->data;
Vsum(t->right, col+1);
 
 
}
typedef queue<tree*> Qtree;
 
 tree::tree()
{
    max_path_l = -1;
 
}
 
int tree::countNodesR(tree* t)
{
 
    if(!t)
    {
        return 0;
    }
    else
    {
        return 1+countNodesR(t->left)+countNodesR(t->right);
    }
}
 
int tree::countLeavesR(tree* t)
{
 
    if(!t)
    {
        return 0;
    }
    else
    {
        if(!(t->right) && !(t->left))
            return 1;
         return countLeavesR(t->left)+countLeavesR(t->right);
    }
}
 
int max(int a,int b)
{
    return a>b?a:b;
}
 
int tree::heightOfTreeR(tree* t)
{
    if(!t)
    {
     return 0;
    }
    else
    {
        int lefth=heightOfTreeR(t->left);
        int righth=heightOfTreeR(t->right);
        if(lefth>righth)
         return lefth+1;
        else
         return righth+1;
    }
}

int tree::max_path_length(tree* t, int max_path_l)
{
    if(!t)
        return 0;
    else
    {
        int lefth = max_path_length(t->left, max_path_l);
        int righth = max_path_length(t->right, max_path_l);
        if(lefth + righth > max_path_l)
            max_path_l = lefth + righth;

        if(lefth>righth)
         return lefth+1;
        else
         return righth+1;
    }
}
 
 
void tree::inorder(tree* root)
{
 
    if(root)
    {
        inorder(root->left);
      cout<<"data="<<root->data<<"\n";
        inorder(root->right);
    }
}
 
void tree::levelorder(tree* root)
{
 
    if(!root)
    {
        cout<<"levelorder::Tree Empty"<<"\n";
    }
    else
    {
        cout<<"LevelOrder Traversal as follows::"<<"\n";
        Qtree qt;
        qt.push(root);
        tree* temp;
 
        while(!qt.empty())
        {
            temp=qt.front();
            qt.pop();
            cout<<"Node="<<temp->data;
            if(temp->parent)
             cout<<",Node->parent="<<temp->parent->data<<"\n";
            else
                cout<<",Node->parent=NULL"<<"\n";
            if(temp->left)
             qt.push(temp->left);
            if(temp->right)
             qt.push(temp->right);
        }
        //qt.clear();
    }
}

 
tree* tree::createTree(int data)
{
    tree* t=new tree;
    t->left=t->right=t->parent=NULL;
    t->data=data;
    return t;
}
 
tree* tree::newNode()
{
    tree* t=new tree;
    t->left=t->right=t->parent=NULL;
    //t->data=data;
    return t;
 
}
 
void tree::addNode(tree* t,int data)
{
    Qtree qt;
    if(!t)
    {
        cout<<"Tree is NULL creating root"<<"\n";
        createTree(data);
    }
    else
    {
        qt.push(t);
        tree* temp;
        while(!qt.empty())
        {
 
            temp=qt.front();
            qt.pop();
            if(temp->left)
            {
                qt.push(temp->left);
            }
            else
            {
                temp->left=newNode();
                temp->left->data=data;
                temp->left->parent=temp;
                cout<<"Node="<<data<<" added to the left"<<"\n";
                qt.pop();
                return;
            }
            if(temp->right)
            {
                qt.push(temp->right);
            }
            else
            {
                temp->right=newNode();
                temp->right->data=data;
                temp->right->parent=temp;
                cout<<"Node="<<data<<" added to the right"<<"\n";
 
                qt.pop();
                return;
            }
 
        }
    }
}
 
int main()
{
    int i = 0;
#if 0
    tree *root;
    while(1)
    {
        cout<<"Enter 1 to add Node, 2 for inorder print, 3 for levelorder print\n\
            4 for count-nodes, 5 for count-leaves, 6 for height of tree\n";
        cin >> i;
        switch(i)
        {
            case 1:
                tree::addNode(i);
                break;
            case 2:
                tree::inorder();
                break;
            case 3:
                break;
            case 4:
                break;
        }
    }
#endif
    tree* root = tree::createTree(100);
    cout<<"Tree Created with Root="<<root->data<<"\n";
 
    root->addNode(root,50);
    cout<<"No of Nodes="<<root->countNodesR(root)<<"\n";
 
    root->addNode(root,40);
    root->addNode(root,30);
    root->addNode(root,20);
    root->addNode(root,10);
    root->addNode(root,5);
    root->addNode(root,2);
    cout<<"Output of Inorder Recursive"<<"\n";
    root->inorder(root);
    root->levelorder(root);
    cout<<"No of Nodes="<<root->countNodesR(root)<<"\n";
 
    cout<<"No of Leaf Nodes="<<root->countLeavesR(root)<<"\n";
    cout<<"Height of Tree="<<root->heightOfTreeR(root)<<"\n";
   cout<<"Max-Path-Length="<<root->max_path_length(root, root->max_path_l)<<"\n";
   Vsum(root,0);
#if 0
    while(1)
    {
     if(i>20)
     break;
     cout<<"hash->"<<hash[i]<<"\n";
     i++;
    }
#endif
    return 0;
}
