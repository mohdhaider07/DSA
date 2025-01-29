#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
bool backtrack(int start, string &s, unordered_set<string> &wordSet, vector<int> &memo)
{
    if (start == s.size())
        return true;
    if (memo[start] != -1)
    {
        return memo[start];
        /* code */
    }

    for (int end = start + 1; end <= s.size(); end++)
    {
        string word = s.substr(start, end - start);
        if (wordSet.find(word) != wordSet.end() & backtrack(end, s, wordSet, memo))
        {
            return memo[start] = true;
        }
        /* code */
    }
    return memo[start] = false;
}
bool wordBreak(string s, vector<string> &wordDict)
{
    unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
    vector<int> memo(s.size(), -1);
    return backtrack(0, s, wordSet, memo);
}
int main()
{
    cout << "word break problem backtracing";
    return 0;
}