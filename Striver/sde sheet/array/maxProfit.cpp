#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int minPrice = INT_MAX, maxProfit = 0;
    for (int price : prices)
    {
        /* code */

        minPrice = min(price, minPrice);
        maxProfit = max(maxProfit, price - minPrice);
    }
    return maxProfit;
}

int main()
{

    cout << "maxProfit" << endl;
    return 0;
}