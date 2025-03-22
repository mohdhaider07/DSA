// cpp template for coding print my name
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int findDuplicate(vector<int> &nums)
{
    int n = nums.size();
    vector<int> count(n, 0);
    for (int num : nums)
    {
        if (count[num] == 1)
            return num;
        count[num]++;
    }
    return -1;
}

int main()
{
    cout << "Hello World";
    return 0;
}