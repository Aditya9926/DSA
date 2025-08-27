#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxProfit(const vector<int>& prices) {
    int minPrice = INT_MAX;
    int maxProfit = 0;

    for (int price : prices) {
        if (price < minPrice) {
            minPrice = price; // Update minimum price
        } else if (price - minPrice > maxProfit) {
            maxProfit = price - minPrice; // Update maximum profit
        }
    }
    return maxProfit;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Maximum Profit: " << maxProfit(prices) << endl; // Output: 5
    return 0;
}