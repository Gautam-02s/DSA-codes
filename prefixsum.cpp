#include <iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++)
    {
      cin>>ar[i];
    }
      
      
  int cursum[n+1];
  cursum[0]=0;

    for(int i=1;i<=n;i++)
    {
      cursum[i]=cursum[i-1]+ar[i-1];
    }

  int maxsum=INT16_MIN;

  for(int i=1;i<=n;i++)
    {
        int sum=0;
        for(int j=0;j<i;j++)
        {
         sum=cursum[i]-cursum[j];
         maxsum=max(maxsum,sum);
        }
    }
    cout<<maxsum;
return 0;
}