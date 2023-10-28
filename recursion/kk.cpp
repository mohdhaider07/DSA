#include <iostream>
#include <vector>
using namespace std;

void letterCombinationsHelper(string &digits, int i, vector<string> &nums, string ansStr, vector<string> &ans)
{

    if (i == digits.size())
    {
        // ansStr
        // vector me push kro
        ans.push_back(ansStr);
        return;
    }

    string str = nums[(digits[i] - '0') - 2];

    for (auto s : str)
    {
        letterCombinationsHelper(digits, i + 1, nums, ansStr + s, ans);
    }
}

vector<string> letterCombinations(string digits)
{

    if (digits.size() == 0)
    {
        return {};
    }

    vector<string> nums = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> ans;

    letterCombinationsHelper(digits, 0, nums, "", ans);

    return ans;
}

int main()
{

    cout << "\nRecursion End!" << endl;
    return 0;
}
