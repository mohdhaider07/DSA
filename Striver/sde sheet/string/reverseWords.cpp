#include <iostream>
#include <string>
#include <vector>
using namespace std;

string reverseWords(string s)
{
    string result = "", word = "";
    int n = s.size();

    for (int i = n - 1; i >= 0; i--)
    {
        /* code */
        if (s[i] != ' ')
        {
            word = s[i] + word;
        }
        else if (!word.empty())
        {
            result += word + " ";
            word = "";
        }
    }
    if (!word.empty())
    {
        result += word;
    }
    if (!result.empty() && result.back() == ' ')
    {
        result.pop_back();
    }
    return result;
}

int main()
{

    cout << "rever the stirng";
    return 0;
}