#include<iostream>
using namespace std;
//#include<malloc.h>
#include<stdlib.h>
#include<queue>

int hashtable[100];
#define COUNT 10
 
 
using namespace std;
 
template <typename T>
class tree
{
    private:
     tree* left;
     tree* right;
     tree* parent;
     static tree* root;
    public:
     T data;
     tree();
     virtual void addNode(tree* t,T data);
     static tree* createTree(T data);
     tree* newNode();
     void print2D(tree* t);
     void print2DUtil(tree* t, int space);
     void inorder(tree* t);
     void levelorder(tree* t);
     int heightOfTreeR(tree* t);
     int countNodesR(tree* t);
     int countLeavesR(tree* t);
     int max_path_length(tree* t, int max_path_l);
     int max_path_l;
     void print_right_view(tree* t);
};
 
// Function to print binary tree in 2D
// It does reverse inorder traversal
template <typename T>
void tree<T>::print2DUtil(tree *root, int space)
{
    // Base case
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    print2DUtil(root->right, space);
 
    // Print current node after space
    // count
    cout<<"\n";
    for (int i = COUNT; i < space; i++)
        cout<<" ";
    cout<<root->data<<"\n";
 
    // Process left child
    print2DUtil(root->left, space);
    //root->print2DUtil(root->left, space);
}
 
// Wrapper over print2DUtil()
template <typename T>
void tree<T>::print2D(tree* root)
{
   // Pass initial space count as 0
   print2DUtil(root, 0);
}
 
#if 0
template <typename T>
queue<tree<T>*> Qtree;
#endif
 
template <typename T>
 tree<T>::tree()
{
    max_path_l = -1;
 
}
 
template <typename T>
int tree<T>::countNodesR(tree* t)
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
 
template <typename T>
int tree<T>::countLeavesR(tree* t)
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
 
template <typename T>
int tree<T>::heightOfTreeR(tree* t)
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

template <typename T>
int tree<T>::max_path_length(tree* t, int max_path_l)
{
    if(!t)
        return 0;
    else
    {
        int lefth = max_path_length(t->left, max_path_l);
        int righth = max_path_length(t->right, max_path_l);
        if(lefth + righth > max_path_l)
            max_path_l = lefth + righth;

        return max(lefth,righth)+1;
    }
}
 
 
template <typename T>
void tree<T>::inorder(tree* root)
{
 
    if(root)
    {
        inorder(root->left);
        cout<<"data="<<root->data<<"\n";
        inorder(root->right);
    }
}
 
template <typename T>
void tree<T>::levelorder(tree* root)
{
#if 0
 
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
#endif
}

 
template <typename T>
tree<T>* tree<T>::createTree(T data)
{
    tree* t=new tree;
    t->left=t->right=t->parent=NULL;
    t->data=data;
    return t;
}
 
template <typename T>
tree<T>* tree<T>::newNode()
{
    tree* t=new tree;
    t->left=t->right=t->parent=NULL;
    //t->data=data;
    return t;
 
}
 
template <typename T>
void tree<T>::addNode(tree* t,T data)
{
#if 0
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
#endif
}
 
int main()
{
    int i = 0;
    tree<int>* root = tree<int>::createTree(100);
    cout<<"Tree Created with Root="<<root->data<<"\n";
#if 0
    tree *root;
//    while(1)
//    {
//        cout<<"Enter 1 to add Node, 2 for inorder print, 3 for levelorder print\n\
//            4 for count-nodes, 5 for count-leaves, 6 for height of tree\n";
//        cin >> i;
//        switch(i)
//        {
//            case 1:
//                tree::addNode(i);
//                break;
//            case 2:
//                tree::inorder();
//                break;
//            case 3:
//                break;
//            case 4:
//                break;
//        }
//    }
 
    root->addNode(root,50);
    cout<<"No of Nodes="<<root->countNodesR(root)<<"\n";
 
    root->addNode(root,40);
    root->addNode(root,30);
    root->addNode(root,20);
    root->addNode(root,10);
    root->addNode(root,5);
    root->addNode(root,2);
    root->print2D(root);
    cout<<"Output of Inorder Recursive"<<"\n";
    root->inorder(root);
    root->levelorder(root);
    cout<<"No of Nodes="<<root->countNodesR(root)<<"\n";
 
    cout<<"No of Leaf Nodes="<<root->countLeavesR(root)<<"\n";
    cout<<"Height of Tree="<<root->heightOfTreeR(root)<<"\n";
    cout<<"Max-Path-Length="<<root->max_path_length(root, root->max_path_l)<<"\n";
#endif
    return 0;
}
