// Design SkipList Algorithm Implementation In C++
#include <iostream>
using namespace std;

// Node class of Singly Linked List
class ListNode {
    // Public Access Modifier
    public:
    int val;
    ListNode *next;
    // Parameterized Constructor
    ListNode(int x) {
        this->val = x;
        this->next = nullptr;
    }
};

// Skiplist class to implement the remove node operation
class Skiplist {
    
    // Public Access Modifier
    public:

    ListNode** head = nullptr;
    
    // Default Constructor
    Skiplist() {}

    // Search Operation
    bool search(int target) {
        ListNode* temp = *head;
        while (temp != nullptr) {
            if (temp->val == target) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Add Operation
    void add(int num) {
        ListNode* newNode = new ListNode(num);
        if (head == nullptr) {
            head = new ListNode*(newNode);
        } else {
            ListNode* temp = *head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Erase Operation
    bool erase(int num) {
        if (head == nullptr) return false;
        ListNode* temp = *head;
        ListNode* prev = nullptr;
        while (temp != nullptr) {
            if (temp->val == num) {
                if (prev == nullptr) {
                    *head = temp->next;
                } else {
                    prev->next = temp->next;
                }
                return true;
            }
            prev = temp;
            temp = temp->next;
        }
        return false;
    }

    // Display Operation
    void display() {
        ListNode* temp = *head;
        while (temp != nullptr) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Main function
int main() {
    
    // Object Of Class
    Skiplist skiplist;

    skiplist.add(1);
    skiplist.add(2);
    skiplist.add(3);
    cout << "Display Skiplist: ";
    skiplist.display();

    cout << "Search 2: " << (skiplist.search(2) ? "Found" : "Not Found") << endl;
    cout << "Erase 2: " << (skiplist.erase(2) ? "Erased" : "Not Found") << endl;
    cout << "Search 2: " << (skiplist.search(2) ? "Found" : "Not Found") << endl;

    cout << "Display Skiplist after Erase: ";
    skiplist.display();

    return 0;
}
