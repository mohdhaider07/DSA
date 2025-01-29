#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

int maxSubArray(vector<int> &nums)
{
    int maxSum = INT_MIN, currentSum = 0;
    for (int num : nums)
    {
        currentSum += num;
        maxSum = max(maxSum, currentSum);

        if (currentSum < 0)
            currentSum = 0;
    }

    return maxSum;
}

int main()
{
    cout << "Mac sun array";
    return 0;
}