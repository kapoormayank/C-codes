// Maximum Binary Tree Algorithm Implementation in C++
#include <iostream>
#include <vector>
using namespace std;

// Node class for the binary tree
class TreeNode {
    // Public Specifier
    public:
    
    // Data Members
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x)
    {
        this->val = x;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Class Solution
class Solution {
    // Public Specifier
    public:
    
    // Data Member
    int index = -1;

    // Build Binary Tree
    TreeNode *buildTree(vector<int> &nums)
    {
        index++;
        if (index >= nums.size() || nums[index] == -1)
        {
            return nullptr;
        }

        // Create a new node with the current value
        TreeNode *node = new TreeNode(nums[index]);

        // Recursively build the left and right subtrees
        node->left = buildTree(nums);
        node->right = buildTree(nums);

        return node;
    }

    // Function to construct the maximum binary tree
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        return buildTree(nums, 0, nums.size() - 1);
    }

    // Helper function to build the tree recursively
    TreeNode *buildTree(vector<int> &nums, int left, int right)
    {
        if (left > right)
        {
            return nullptr;
        }

        // Find the index of the maximum element in the current range
        int maxIndex = left;
        for (int i = left; i <= right; i++)
        {
            if (nums[i] > nums[maxIndex])
            {
                maxIndex = i;
            }
        }

        // Create a new node with the maximum value
        TreeNode *root = new TreeNode(nums[maxIndex]);

        // Recursively build the left and right subtrees
        root->left = buildTree(nums, left, maxIndex - 1);
        root->right = buildTree(nums, maxIndex + 1, right);

        return root;
    }

    // Display Binary Tree
    void display(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        cout << root->val << " ";
        display(root->left);
        display(root->right);
    }
};

// Main function
int main()
{
    vector<int> nums = {3, 2, 1, 6, 0, 5};

    Solution solution;

    TreeNode *root = solution.buildTree(nums);
    cout << "Binary Tree (Preorder Traversal): ";
    solution.display(root);

    TreeNode *maxRoot = solution.constructMaximumBinaryTree(nums);

    cout << "\nMaximum Binary Tree (Preorder Traversal): ";

    solution.display(maxRoot);
    return 0;
}
