// #include <iostream>
// #include<vector>
// using namespace std;

// int slidingwindow(const vector<int>&arr,int k)
// {
//      int sum=0;
//   for(int i=0;i<k;i++)
//   {
//     int sum=sum+arr[i];
//   }
//   int maxsum=sum;
//   for(int j=k;j<arr.size();j++)
//   {
//     sum=sum+sum[j]+sum[j-k];
//     maxsum=max(sum,maxsum);
//   }

// }

// int main()
// {
 
// return 0;
// }


#include <iostream>
#include <vector>
using namespace std;

int maxSumKElements(const vector<int>& nums, int k) {
    int max_sum = 0;
    for (int i = 0; i < k; ++i)
        max_sum += nums[i];

    int current_sum = max_sum;
    for (size_t i = k; i < nums.size(); ++i) {
        current_sum += nums[i] - nums[i - k];
        max_sum = max(max_sum, current_sum);
    }

    return max_sum;
}

int main() {
    vector<int> nums = {1, 8, 30, -5, 20, 7};
    int k = 3;
    cout << "Maximum Sum of " << k << " consecutive elements: " << maxSumKElements(nums, k) << endl;
}
