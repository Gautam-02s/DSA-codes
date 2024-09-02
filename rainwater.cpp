#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int trap(vector<int>& nums) 
{
    int total = 0;

    for(int i = 0; i < nums.size(); i++)
    {
        int leftmax = 0, rightmax = 0;

        // Find the maximum height to the left of the current bar
        for(int j = 0; j <= i; j++)
        {
            leftmax = max(leftmax, nums[j]);
        }

        // Find the maximum height to the right of the current bar
        for(int k = i; k < nums.size(); k++)
        {
            rightmax = max(rightmax, nums[k]);
        }
        
        // Calculate water trapped at the current position and add it to the total
        total += min(leftmax, rightmax) - nums[i];
    }
    
    return total;
}

int main()
{
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "Total water trapped: " << trap(height) << endl; // Output: 6

    return 0;
}
