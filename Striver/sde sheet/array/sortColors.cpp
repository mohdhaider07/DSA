#include <iostream>
#include <vector>
#include <string>

using namespace std;

void sortColors(vector<int> &nums)
{
    vector<int> count(3, 0);
    for (int num : nums)
    {
        count[num]++;
    }
    int x = 0;
    for (int i = 0; i < count.size(); i++)
    {
        for (int j = 0; j < count[i]; j++)
        {
            nums[x] = i;
            x++;
        }
    }
}

int main()
{
    cout << "sortColors";
    return 0;
}