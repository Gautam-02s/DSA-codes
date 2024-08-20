#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int binarysearch(int arr[],int key)
    {
        int l=arr[0];
        int r=arr[n-1];
        int mid=n/2;

        while(l<r)
        {
            if(mid==key)
            {
                return 1;
            }
            else if (key<mid)
            {
                mid=l
            }
            else{
                mi
            }
        }
        
    }
    
return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int binarySearch(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;  // Avoids potential overflow

        if (arr[mid] == target)
            return mid;  // Target found at index mid
        else if (arr[mid] < target)
            left = mid + 1;  // Search in the right half
        else
            right = mid - 1;  // Search in the left half
    }

    return -1;  // Target not found
}

int main() {
    vector<int> arr = {2, 3, 4, 10, 40};
    int target = 10;
    
    int result = binarySearch(arr, target);
    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found" << endl;
}
