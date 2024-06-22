#include <iostream>
#include <vector>
using namespace std;

vector<int> subarraySum(vector<int> arr, int n, long long s)
{
    // Your code here
    int end = 0;
    int start = 0;
    // long long sum = 0;
    while (end < n)
    {
        s = s - arr[end];

        while (0 > s)
        {
            s = s + arr[start];
            start++;
        }

        if (0 == s)
        {
            if (start > end)
            {
                end++;
                continue;
            };
            return {start + 1, end + 1};
        }
        end++;
    }
    return {-1};
}

int main()
{
    cout << "Hello, World!" << endl;
    return 0;
}