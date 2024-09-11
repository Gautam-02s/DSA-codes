#include <iostream>
#include <vector>
#include <algorithm>

// Function to find the maximum gift voucher value
int maxGiftVoucherValue(int budget, const std::vector<int>& prices, const std::vector<int>& vouchers) {
    int n = prices.size();
    std::vector<int> dp(budget + 1, 0);

    for (int i = 0; i < n; ++i) {
        for (int j = budget; j >= prices[i]; --j) {
            dp[j] = std::max(dp[j], dp[j - prices[i]] + vouchers[i]);
        }
    }

    return dp[budget];
}

int main() {
    int n, budget;
    std::cout << "Enter the number of items and budget: ";
    std::cin >> n >> budget;

    std::vector<int> prices(n), vouchers(n);
    std::cout << "Enter the prices of the items: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> prices[i];
    }

    std::cout << "Enter the gift voucher values of the items: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> vouchers[i];
    }

    int maxValue = maxGiftVoucherValue(budget, prices, vouchers);
    std::cout << "Maximum gift voucher value: " << maxValue << std::endl;

    return 0;
}
