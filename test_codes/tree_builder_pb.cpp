
/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <list>

#define COUNT 10
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    ~Node()
    {
        
    }
};

struct Input {
    string edge;
    int data;
};

class TreeBuilder {
    private:
    list<Input> m_input;
    Node* m_root;
    void deleteTree(Node* node)
    {
        if(NULL == node) {
            return;
        }
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
    public:
    TreeBuilder(int root_data)
    {
        m_root = new Node(root_data);
    }
    ~TreeBuilder()
    {
        deleteTree(m_root);
    }
    Node* getTree()
    {
        return m_root;
    }
    void input(string& edge, int data)
    {
        Input inp;
        inp.edge = edge;
        inp.data = data;
        m_input.push_back(inp);
    }
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
        cout<<"\n";
        for (int i = COUNT; i < space; i++)
            cout<<" ";
        cout<<root->data<<"\n";
     
        // Process left child
        print2DUtil(root->left, space);
        //root->print2DUtil(root->left, space);
    }
 
    // Wrapper over print2DUtil()
    void print2D(Node* root)
    {
       root = m_root;
       // Pass initial space count as 0
       print2DUtil(root, 0);
    }
    void buildTree()
    {
        Node* temp = NULL;
        for(auto itr = m_input.begin(); itr != m_input.end(); itr++) {
            temp = m_root;
            const char* str = (*itr).edge.c_str();
            int len = (*itr).edge.size();
            for(int i = 0; i < (len); i++) {
                if(NULL == temp) {
                    m_input.push_back(*itr);
                    itr = m_input.erase(itr);
                    itr--;
                    break;
                }
                
                if(i == (len-1)) {
                    if(str[len-1] == 'R') {
                        temp->right = new Node((*itr).data);
                    } else {
                        temp->left = new Node((*itr).data);
                    }
                } else {
                    if(str[i] == 'R') {
                        temp = temp->right;
                    } else {
                        temp = temp->left;
                    }
                }
            }
            
        }
    }
};

int calculateDiameter(Node* root, int& dia)
{
    int l_dia, r_dia;
    if(NULL == root) {
        return 0;
    }
    l_dia = calculateDiameter(root->left, dia);
    r_dia = calculateDiameter(root->right, dia);
    if(dia < (l_dia + r_dia + 1)) {
        dia = l_dia + r_dia + 1;
    }
    if(l_dia > r_dia) {
        return l_dia+1;
    }
    return r_dia+1;
}

int main() {
    int num, dia = 0, data = 0;
    string str;
    cout<<"Enter number of nodes to be inserted"<<endl;
    cin >> num;                                     // Reading input from STDIN
    //cout << "Input number is " << num << endl;        // Writing output to STDOUT
    cin >> data;
    TreeBuilder* tree = new TreeBuilder(data);
    for(int i = 0; i < num; i++) {
        cout<<"Enter 'R' or 'L' and following with data" <<endl;
        cin >> str;
        cin >> data;
        tree->input(str, data);
    }
    tree->buildTree();
    Node root(0);
    tree->print2D(&root);
    calculateDiameter(tree->getTree(), dia);
    cout << dia;
    delete tree;
}
