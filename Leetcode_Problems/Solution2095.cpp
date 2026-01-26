// Leet Code Problem 2095: Delete the Middle Node of a Linked List
#include<iostream>
using namespace std;

class ListNode{
    // Default Access Modifier And Data Memebers
    public:
    int data;
    ListNode* next;
    // Parameterized Constructor
    public:
    ListNode(int data){
        this->data=data;
        this->next=nullptr;
    }
};
class Solution328{
    public:
    ListNode* head=nullptr;
    // Method to insert the elements in linked list
    void insert(int data){
        ListNode* newNode = new ListNode(data);
        if(head == nullptr){
            head = newNode;
        }else{
            ListNode* temp=head;
            while(temp->next != nullptr){
                temp=temp->next;
            }
            temp->next=newNode;
        }
    }

    // Method to dlete middle node elements from linked list
    void deleteMiddle() {
        if(head == nullptr || head->next == nullptr){
            head=head->next;
        }
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast->next != nullptr && fast->next->next != nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=slow->next->next;
    }

    // Method to display the linked list data
    void display(){
        if(head == nullptr){
            cout<<"Empty Linked List!!!"<<endl;
        }else{
            ListNode* temp=head;
            while(temp != nullptr){
                cout<<temp->data<<"-->";
                temp=temp->next;
            }
            cout<<"nullptr"<<endl;
        }
    }
};

// Main function 
int main(){
    Solution328 list;
    cout<<"Enter number of terms: ";
    int n,value;
    cin>>n;
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++){
        cin>>value;
        list.insert(value);
    }
    cout<<"Original Linked List: ";
    list.display();
    list.deleteMiddle();
    cout<<"After deleting middle node element from linked list : ";
    list.display();
    return 0;
}
