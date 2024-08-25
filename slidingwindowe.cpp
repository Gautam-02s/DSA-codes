#include <iostream>
#include <vector>
using namespace std;

int sum(vector<int> &nums, int k)
{
    int maxsum=0;;
    for(int i=0;i<k;i++)
    {
        maxsum+=nums[i];
    }
    int cursum=maxsum;

    for(int i=k;i<nums.size();i++)
    {
        cursum+=nums[i]-nums[i-k];

        if(cursum>maxsum)
        {
            maxsum=cursum;
        }
    }
    return maxsum;
}

int main()
{
   vector<int>arr={2, 1, 5, 1, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    cout << "Maximum sum of a subarray of length " << k << " is " << sum(arr,k) << endl;
return 0;
}