#include <iostream>
using namespace std;
int main()
{
    int ar[3][3]={1,2,3,4,5,6,7,8,9};

    for(int i=0;i<3;i++)
    {
        for(int j=i;j<3;j++)
        {
         int temp=ar[i][j];
         ar[i][j]=ar[j][i];
         ar[j][i]=temp;
        }
    }

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
         cout<<ar[i][j]<<" ";
        }
        cout<<endl;
    }
return 0;
}