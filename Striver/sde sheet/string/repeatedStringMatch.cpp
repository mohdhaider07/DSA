#include <iostream>
#include <string>

using namespace std;

int repeatedStringMatch(string a, string b)
{
    string repeated = a;
    int count = 1;
    while (repeated.size() < b.size())
    {
        /* code */
        repeated += a;
        count++;
    }

    // if b is present in the stirng or not
    if (repeated.find(b) != string ::npos)
        return count;

    repeated += a;

    if (repeated.find(b) != string::npos)
    {
        /* code */
        return count + 1;
    }

    return -1;
}

int main()
{

    cout << "Hi repeatedStringMatch";
    return 0;
}
