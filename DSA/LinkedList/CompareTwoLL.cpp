// Compare two Linked Lists Algorithm Implementation In C++
#include<iostream>
using namespace std;

// Class for Node
class Node {

    // Data Members And Public Access Specifier
    public:
    int data;
    Node* next;

    // Parameterized Constructor
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }

    public:
    Node* head = nullptr;

    // Insert
    Node* insert(Node* head,int data) {
        Node* newNode = new Node(data);
        if(head == nullptr) {
            head = newNode;
            return head;
        }
        else {
            Node* temp = head;
            while(temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        return head;
    }

    // Compare Two Linked Lists
    bool compare(Node* head1, Node* head2) {
        if(head1 == nullptr && head2 == nullptr) {
            return true;
        }

        Node* temp1 = head1;
        Node* temp2 = head2;
        while(temp1 != nullptr && temp2 != nullptr) {
            if(temp1->data != temp2->data) {
                return false;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return (temp1 == nullptr && temp2 == nullptr);
    }

    // Print
    void print(Node* head) {
        Node* temp = head;
        while(temp != nullptr) {
            cout << temp->data << "-->";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Main function
int main() {
    Node* head1 = nullptr;
    Node* head2 = nullptr;
    
    Node* node = new Node(0); // Create a dummy node to use member functions

    // Insert elements in first linked list
    head1 = node->insert(head1, 1);
    head1 = node->insert(head1, 2);
    head1 = node->insert(head1, 3);

    // Second Linked List
    head2 = node->insert(head2, 1);
    head2 = node->insert(head2, 2);
    head2 = node->insert(head2, 3);

    cout << "List 1: ";
    node->print(head1);
    cout << "List 2: ";
    node->print(head2);

    if(node->compare(head1, head2)) {
        cout << "Both lists are identical." << endl;
    } else {
        cout << "Lists are not identical." << endl;
    }

    return 0;
}

