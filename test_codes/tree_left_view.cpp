#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<stack>
#include<queue>
#include<map>
using namespace std;
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
    //printf("Entry in rightViewUtil\n");
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

int max(int, int);

int diameter(Node* root, int* h)
{
	int lh =0, rh =0;
	int ld =0, rd =0;
	if(!root)
	{
		*h = 0;
		return 0;
	}
	
	ld = diameter(root->left, &lh);
	rd = diameter(root->right, &rh);
	*h = max(lh, rh) + 1;
	return max(max(ld, rd), lh+rh+1);
		
}
int max(int a, int b)
{
	return a>b?a:b;
}
stack<Node*>s1;
stack<Node*>s2;

void print_zig_zag(Node* root)
{
	print2D(root);
	cout<<"inside zigzag "<<endl;
	s1.push(root);
	cout<<root->data<<endl;
	while((!s1.empty()) || (!s2.empty()))
	{
		while(!s1.empty())
		{
			Node* tmp = s1.top();
			s1.pop();
			cout<<"s1: "<<tmp->data<<" ,";
			if(tmp->right)
			{
				s2.push(tmp->right);
			}
			if(tmp->left)
			{
				s2.push(tmp->left);
			}
		}

		while(!s2.empty())
		{
			Node* tmp = s2.top();
			s2.pop();
			cout<<"s2: "<<tmp->data<<" ,";
			if(tmp->left)
			{
				s1.push(tmp->left);
			}
			if(tmp->right)
			{
				s1.push(tmp->right);
			}
		}
	}
}
void pre_order(Node* root)
{
	if(!root)
		return;
	printf("%d ,", root->data);
	pre_order(root->left);
	pre_order(root->right);
}

void post_order(Node* root)
{
	if(!root)
		return;
	pre_order(root->left);
	pre_order(root->right);
	printf("%d ,", root->data);
}

void in_order(Node* root)
{
	if(!root)
		return;
	in_order(root->left);
	printf("%d ,", root->data);
	in_order(root->right);
}

void leftView(Node* root, int *max_level, int level) {
    if(!root) {
        return;
    }
    if(*max_level<level)
    {
        *max_level = level;
        cout<<root->data<<"\t";
    }
    leftView(root->left, max_level, level+1);
    leftView(root->right, max_level, level+1);
}

queue<Node*>ql;
void print_level_order(Node *root) {
    if(!root) return;
    ql.push(root);
    while(!ql.empty()) {
        Node *tmp;
        tmp = ql.front();
        cout<<tmp->data<<"\t";
        ql.pop();
        if(tmp->left) {
            ql.push(tmp->left);
        }
        if(tmp->right) {
            ql.push(tmp->right);
        }
    }
}
typedef struct {
    Node* n;
    int hd;
}bottom_s;

queue<bottom_s> qb;
void bottomView(Node *root) {
    map<int, int> m1;
    if(!root) return;
    bottom_s bs;
    bs.n=root;
    bs.hd=0;
    qb.push(bs);
    int hd = 0;
    while(!qb.empty()) {
        bs = qb.front();
        Node* tmp = bs.n;
        m1[bs.hd] = bs.n->data;
        hd = bs.hd;
        cout<<"hd = "<<bs.hd<<", data = "<<bs.n->data <<"  ||";
        //cout<<tmp->data<<"\t";
        qb.pop();
        if(tmp->left) {
            bs.n=tmp->left;
            bs.hd = hd -1 ;
            qb.push(bs);
        }
        if(tmp->right) {
            bs.n=tmp->right;
            bs.hd = hd + 1;
            qb.push(bs);
        }
    }
    for(auto it=m1.begin(); it!=m1.end(); ++it)
    {
        cout<<(*it).second<<"\t";
    } 
}

int no_of_leafs(Node* root)
{
    if(!root) return 0;
    if(!root->left && !root->right)
        return 1;
    return no_of_leafs(root->left) + no_of_leafs(root->right);
}

int max_path_sum_util(Node* root, int &res) {
    if(!root) return 0;
    if(!root->left && !root->right) return root->data;
    int ls = max_path_sum_util(root->left, res);
    int rs = max_path_sum_util(root->right, res);
    if(root->left && root->right) {
        res = max(res, ls+rs+root->data); 
        return max(ls,rs) + root->data;
    }
    else if(!root->left) {
        return rs+root->data;
    }
    else {
        return ls+root->data;
    }
}

int max_path_sum(Node* root) {
    int res = INT_MIN;
    max_path_sum_util(root, res);
    cout<<"Max path sum = "<<res<<endl;;
}

int find_largest(Node* root) {
    if(!root) return 0;
    int lmx = find_largest(root->left);
    int rmx = find_largest(root->right);
    cout<<"lmx = "<<lmx<<", rmx = "<<rmx<<", root->data = "<<root->data<<endl;
    return max(lmx, max(rmx, root->data)); 
    
}
// Driver Program to test above functions
int main()
{
    struct Node *root = newNode(1);
#if 0
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->left = newNode(10);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
#endif
    root->left = newNode(5); 
    root->right = newNode(6); 
    root->left->left = newNode(-8); 
    root->left->right = newNode(1); 
    root->left->left->left = newNode(2); 
    root->left->left->right = newNode(6); 
    root->right->left = newNode(3); 
    root->right->right = newNode(9); 
    root->right->right->right= newNode(0); 
    root->right->right->right->left= newNode(4); 
    root->right->right->right->right= newNode(-1); 
    root->right->right->right->right->left= newNode(10); 
    print2D(root);
    int mx = 0;
    cout<<"==========================="<<endl;
    cout<<"max-ele = "<<find_largest(root)<<endl;
    cout<<"==========================="<<endl;
    cout<<"no of leafs = "<<no_of_leafs(root)<<endl;
    max_path_sum(root);
    //cout<<"=======level order start======"<<endl;
    //print_level_order(root);
    //cout<<"=======level order end======"<<endl;
    //rightView(root);
    //cout<<"=======right view end======"<<endl;
    //int max_level = 0;
    //leftView(root, &max_level, 1);
    cout<<"=======bottom view start======"<<endl;
    bottomView(root);
    cout<<"=======bottom view end======"<<endl;
#if 0
    rightView_another(root, level);
    for(int i=0; i<20; i++)
    {
        if(arr[i]!=NULL)
        {
        printf("%d\n",arr[i]->data);
        }
    }
    printf("*************************\n");

    int h;
    printf("diameter = %d\n",diameter(root, &h));
    print_zig_zag(root);
    print2D(root);

    printf("PRE order \n"); 
    pre_order(root);
    printf("\nPOST order \n"); 
    post_order(root);
    printf("\nIN order \n"); 
    in_order(root);
#endif
    return 0;
}
