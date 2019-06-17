#include<stdio.h>
#include<stdlib.h>

#define COUNT 10

struct Node {
	int data;
	Node* left;
	Node* right;
	Node* parent;

};

Node* newNode(int item, Node* parent)
{
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->left = NULL;
	tmp->right = NULL;
	tmp->parent = parent;
	tmp->data = item;
	return tmp;
}

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

Node* findRightSibling(Node* node, int level)
{
	if(node==NULL || node->parent == NULL)
		return NULL;
	
	while(node->parent->right == node || 
	    (node->parent->left == node && node->parent->right == NULL))
	{
		if(node->parent == NULL)
			return NULL;

		node=node->parent;
		level--;
	}
	printf("node: %d\n", node->data);
	node = node->parent->right;
	while(level<0)
	{
		if(node->left)
			node=node->left;
		else if(node->right)
			node= node->right;
		else
			break;
		level++;
	}
	if(!level)
		return node;


	printf("node: %d, level=%d\n\n", node->data, level);
	return findRightSibling(node, level);
	
}
int sum_node(Node* root, int* sum)
{
	if(!root)
		return 0;
	sum_node(root->left, sum);
	*sum += root->data;
	sum_node(root->right, sum);
	return *sum;
}

int main() 
{ 
    Node* root = newNode(1, NULL); 
    root->left = newNode(2, root); 
    root->right = newNode(3, root); 
    root->left->left = newNode(4, root->left); 
    root->left->right = newNode(6, root->left); 
    root->left->left->left = newNode(7, root->left->left); 
    root->left->left->left->left = newNode(10, root->left->left->left); 
    root->left->right->right = newNode(9, root->left->right); 
    root->right->right = newNode(5, root->right); 
    root->right->right->right = newNode(8, root->right->right); 
    root->right->right->right->right = newNode(12, root->right->right->right); 
    print2D(root);
  
    // passing 10 
    Node *res = findRightSibling(root->left->left->left->left, 0); 
    if (res == NULL) 
       printf("No right sibling"); 
    else
       printf("%d", res->data); 

    printf("************\n");
    int sum = 0;
    printf("sum-node = %d\n", sum_node(root, &sum));
  
    return 0; 
} 
