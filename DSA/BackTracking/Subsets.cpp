// Subsets Generation using Backtracking Algorithm Implementation in C++
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    // Function to generate subsets using backtracking
    void subset(vector<int>& nums, vector<vector<int>>& result, vector<int>& temp, int index) {
        // Add current subset
        result.push_back(temp);
        for(int i = index; i < nums.size(); i++) {
            // Include element
            temp.push_back(nums[i]);
            // Recursive call
            subset(nums, result, temp, i + 1);
            // Backtrack (remove last element)
            temp.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        subset(nums, result, temp, 0);
        return result;
    }
};

// Main function
int main() {
    
    Solution obj;
    cout<<"Enter number of elements: ";
    int n;
    cin >> n;
    vector<int> nums(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<vector<int>> result = obj.subsets(nums);
    cout << "Subsets are:\n";
    for(auto subset : result) {
        cout << "[ ";
        for(int num : subset) {
            cout << num << " ";
        }
        cout << "]\n";
    }
    return 0;
}

