#include <iostream>
#include <vector>
using namespace std;

vector<int> removeduplicates(vector<int> &nums)
{
    int k=1;
    for(int i=1;i<nums.size();i++)
    {
         if(nums[i]!=nums[i-1])
         {
            nums[k]=nums[i];
            k++;
         }
    }
    nums.resize(k);
    return nums;
}

int main()
{
 vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 5}; 
    vector<int> unique_nums =removeduplicates(nums);

    cout << "The array after removing duplicates: ";
    for (int num : unique_nums) {
        cout << num << " ";
    }
    cout << endl;


return 0;
}