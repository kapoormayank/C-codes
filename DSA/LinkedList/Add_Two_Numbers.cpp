// Add Two Numbers Algorithm Implementation In C++
// Time Complexity: O(max(m,n))
// Space Complexity: O(max(m,n))
#include<iostream>
#include<vector>
using namespace std;

// Class Of Singly Linked List
class ListNode {
    
    // Public Access Modifier
    public:
    int val;
    ListNode *next;
    
    // Parmaterized Constructor
    ListNode(int x) {
        this->val = x;
        this->next = nullptr;
    }
};

// Class Solution
class Solution {
    // Public Access Modifier
    public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;
            if(l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum/10;
            current->next = new ListNode(sum%10);
            current = current->next;
        }

        return dummy->next;
    }
};

// Main function
int main() {
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    Solution solution;
    ListNode* result = solution.addTwoNumbers(l1, l2);

    cout << "Resultant Linked List: ";
    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }

    return 0;
}



