#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int romanToInt(string s)
{
    unordered_map<char, int> romanMap = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    int total = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (i < s.size() - 1 && romanMap[s[i]] < romanMap[s[i + 1]])
        {
            total = total - romanMap[s[i]];
        }
        else
        {
            total += romanMap[s[i]];
        }
    }
    return total;
}

int main()
{
    cout << "romantoint";
    return 0;
}