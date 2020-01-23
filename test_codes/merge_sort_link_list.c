#include<iostream>
#include<cstdlib>
using namespace std;

class Node {
    public:
        Node* next;
        int data;
};
void printList(Node* node);

void FrontBackSplit(Node* head_ref, Node** front_ref, Node** back_ref) {
    Node* slow;
    Node* fast;
    slow = head_ref;
    fast = head_ref->next;
    while(fast!=NULL) {
        fast = fast->next;
        if(fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    //cout<<"slow "<<slow->data<<endl;
    *front_ref = head_ref;
    *back_ref = slow->next;
    slow->next = NULL;
    //printList(head_ref);
    //printList(*back_ref);
}

Node* SortedMerge(Node* a, Node *b);
void MergeSort(Node** head_ref) {
    Node* head = *head_ref;
    Node* a; Node* b;
    if((head==NULL) || (head->next == NULL)) {
        return;
    }

    FrontBackSplit(head, &a, &b);
    cout<<"inside mergesort "<<endl;
    printList(a);
    printList(b);
    cout<<"inside mergesort end"<<endl;
    MergeSort(&a);
    MergeSort(&b);
    *head_ref = SortedMerge(a, b);
    printList(a);
}

Node* SortedMerge(Node* a, Node *b) {
    Node* result = NULL;
    if(a == NULL) return (b);
    else if(b == NULL) return (a);
    cout<<"*********sorted merge*****"<<endl;
    printList(a);
    printList(b);
    cout<<"*********sorted merge*end****"<<endl;
    
    if(a->data > b->data) {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    else {
        result = a;
        result->next = SortedMerge(a->next, b);
    }

    return (result);
}

void push(Node** head_ref, int new_data) 
{ 
    /* allocate node */
    Node* new_node = new Node(); 
  
    /* put in the data */
    new_node->data = new_data; 
  
    /* link the old list off the new node */
    new_node->next = (*head_ref); 
  
    /* move the head to point to the new node */
    (*head_ref) = new_node; 
} 
void printList(Node* a) {
//	while (node != NULL) { 
//		cout << node->data << " "; 
//		node = node->next; 
//	} 
    if(a==NULL) {cout<<"NULL"<<endl;return;}
    cout<<"["<<a->data<<"]->";
    printList(a->next);
}
  
/* Driver program to test above functions*/
int main() 
{ 
    /* Start with the empty list */
    Node* res = NULL; 
    Node* a = NULL; 
  
    /* Let us create a unsorted linked lists to test the functions  
 * Created lists shall be a: 2->3->20->5->10->15 */
    push(&a, 15); 
    push(&a, 10); 
    push(&a, 5); 
    push(&a, 20); 
    push(&a, 3); 
    push(&a, 2); 
  
    printList(a); 
    /* Sort the above created Linked List */
    MergeSort(&a); 
  
    cout << "Sorted Linked List is: \n"; 
    printList(a);
  
    return 0; 
} 
