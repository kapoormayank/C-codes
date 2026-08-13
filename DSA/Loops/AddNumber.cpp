// Add Number Algorithm Implementation In C++
#include<iostream>
using namespace std;

// Class Solution
class Solution{
    public :

    // Function to add digits of a number until a single digit is obtained
    int addDigits(int num)
    {
        if (num == 0)
        {
            return 0;
        }

        return 1 + (num - 1) % 9;
    }
};

// Main function
int main()
{
    Solution solution;
    int num;

    cout << "Enter a number: ";
    cin >> num;

    int result = solution.addDigits(num);
    cout << "The single digit obtained by adding the digits of " << num << " is: " << result << endl;

    return 0;
}
