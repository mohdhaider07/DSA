// sample code for c++
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

// TODO: 1.  https://takeuforward.org/data-structure/maximum-xor-of-two-numbers-in-an-array/
//           https : // www.youtube.com/watch?v=EIhAwfHubE8&list=PLgUwDviBIf0pcIDCZnxhv0LkHf5KzG9zp&index=7
// TODO: 2.  https://takeuforward.org/trie/maximum-xor-queries-trie/

void AllPossibleStringsHelper(string s, int index, string word, vector<string> &ans)
{
    // int size of the string
    int n = s.size();
    if (index >= n)
    {
        ans.push_back(word);
        return;
    }

    AllPossibleStringsHelper(s, index + 1, word + s[index], ans);
    AllPossibleStringsHelper(s, index + 1, word, ans);
}
vector<string> AllPossibleStrings(string s)
{
    // Code here
    int n = s.size();
    vector<string> ans;
    // iterate to all the power set
    for (int i = 0; i < pow(2, n) - 1; i++)
    {
        // iterate to size for the word for indexing
        string str = "";
        for (int j = 0; j < n; j++)
        {
            // left shift of 1, j times
            if (i & (1 << j))
            {
                str = str + s[j];
            }
        }
        ans.push_back(str);
    }
    return ans;
}

int main()
{

    cout << "Trie p1.cpp for c++" << endl;

    return 0;
} // Output: 1 2 3 4 5
