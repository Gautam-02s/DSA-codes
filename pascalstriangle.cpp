#include <iostream>
#include<algorithm>
using namespace std;

int fact(int n)
{
    if(n==0||n==1)
    {
        return 1;
    }
    return n*fact(n-1);
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<i;j++)
        {
            cout<<fact(i)/(fact(i-j)*fact(j))<<" ";
        }
      cout<<endl;
    }
    
return 0;
}




