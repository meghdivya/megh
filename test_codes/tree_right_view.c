#include<stdio.h>
#include<stdlib.h>
#define COUNT 10
struct Node
{
    int data;
    struct Node *left, *right;
};
// A utility function to create a new Binary Tree Node
struct Node *newNode(int item)
{
    struct Node *temp =  (struct Node *)malloc(sizeof(struct Node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node* arr[20] = {0};

// Function to print binary tree in 2D
// It does reverse inorder traversal
void print2DUtil(Node *root, int space)
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
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n",root->data);
 
    // Process left child
    print2DUtil(root->left, space);
    //root->print2DUtil(root->left, space);
}

// Wrapper over print2DUtil()
void print2D(Node* root)
{
   //root = m_root;
   // Pass initial space count as 0
   print2DUtil(root, 0);
}
// Recursive function to print right view of a binary tree.
void rightViewUtil(struct Node *root, int level, int *max_level)
{
    printf("Entry in rightViewUtil\n");
    // Base Case
    if (root==NULL)  return;
    // If this is the last Node of its level
    if (*max_level < level)
    {
        printf("level-%d,maxlevel=%d,data=%d\n",level,*max_level, root->data);
        *max_level = level;
    }
    // Recur for right subtree first, then left subtree
    rightViewUtil(root->right, level+1, max_level);
    rightViewUtil(root->left, level+1, max_level);
}

void rightView_another(struct Node* root, int level)
{
    printf("Entry in rightViewAnother\n");
    if(root==NULL) return;
    arr[level] = root;
    rightView_another(root->left, level+1);
    rightView_another(root->right, level+1);
}

// A wrapper over rightViewUtil()
void rightView(struct Node *root)
{
    int max_level = 0;
    rightViewUtil(root, 1, &max_level);
}
// Driver Program to test above functions
int main()
{
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    print2D(root);
    rightView(root);
    int level = 0;
    rightView_another(root, level);
    for(int i=0; i<20; i++)
    {
        if(arr[i]!=NULL)
        {
        printf("%d\n",arr[i]->data);
        }
    }
    return 0;
}
