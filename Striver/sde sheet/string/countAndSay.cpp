#include <iostream>
#include <string>

using namespace std;

string getNextSequence(string s)
{
    string result = "";
    int count = 1;
    for (int i = 1; i <= s.size(); i++)
    {
        if (i == s.size() || s[i] != s[i - 1])
        {
            result += to_string(count) + s[i - 1];
            count = 1;
        }
        else
        {
            count++;
        }
    }
    return result;
}

string countAndSay(int n)
{
    if (n == 1)
    {
        return "1";
    }
    return getNextSequence(countAndSay(n - 1));
}

int main()
{

    cout << "countAndSay";
    return 0;
}