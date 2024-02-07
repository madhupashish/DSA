#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* next;
};    
 
// Function that allocates a new
// node with given data
Node* newNode(int data)
{
    Node* new_node = new Node;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
 
// Function to insert a new node
// at the end of linked list
Node* insertEnd(Node* head, int data)
{
    // If linked list is empty,
    // Create a new node
    if (head == NULL)
        return newNode(data);
 
    // If we have not reached the end
    // Keep traversing recursively
    else
        head->next = insertEnd(head->next, data);
    return head;
}
 
/// Function to traverse given LL
void traverse(Node* head)
{
    if (head == NULL)
        return;
 
    // If head is not NULL,
    // print current node and
    // recur for remaining list
    cout << head->data << " ";
 
    traverse(head->next);
}
 
// Driver Code
int main()
{
    // Given Linked List
    Node* head = NULL;
    head = insertEnd(head, 1);
    head = insertEnd(head, 2);
    head = insertEnd(head, 3);
    head = insertEnd(head, 4);
 
    // Function Call to traverse LL
    traverse(head);
}