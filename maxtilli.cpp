#include <iostream>
#include<algorithm>
using namespace std;
int main()
{
    int ar[]={1,0,5,4,6,8};
    int high=INT16_MIN;
    int res=0;
    for(int i=0;i<6;i++)
    {
     res=max(high,ar[i]);
     high=ar[i];
     cout<<res<<" ";
    }
return 0;
}