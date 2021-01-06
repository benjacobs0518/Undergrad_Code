#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <set>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

void printList(Node* n)
{
    while (n != NULL) {
        cout << n->data << " ";
        n = n->next;
    }
  cout<<endl;
}

void reverse(struct Node **head_ref) {
    struct Node *temp = NULL;
    struct Node *prev = NULL;
    struct Node *current = (*head_ref);
    while(current != NULL) {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    (*head_ref) = prev;
}

int main() {
std::cout<<"Test"<<std::endl;

Node *head = new Node();
Node *first = new Node();
Node *second = new Node();

head->data = 0;
first->data = 1;
second->data = 2;

head->next = first;
first->next = second;
second->next = NULL;

printList(head);
reverse(&head);
printList(head);

}
