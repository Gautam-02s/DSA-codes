#include <iostream>
#include <climits> // For INT_MAX
using namespace std;

int maxprofit(int ar[], int n)
{
    int minPrice = INT_MAX; // Initialize minPrice to a very high value
    int maxProfit = 0; // Initialize maxProfit to 0

    for(int i = 0; i < n; i++)
    {
        // Update minPrice if current price is lower
        if(ar[i] < minPrice)
        {
            minPrice = ar[i];
        }

        // Calculate profit if sold at current price, and update maxProfit
        int profit = ar[i] - minPrice;
        if(profit > maxProfit)
        {
            maxProfit = profit;
        }
    }

    return maxProfit;
}

int main()
{
    int prices[] = {7, 1, 5, 3, 6, 4};
    int n = sizeof(prices) / sizeof(prices[0]);

    int result = maxprofit(prices, n);
    cout << "Maximum Profit: " << result << endl;

    return 0;
}
