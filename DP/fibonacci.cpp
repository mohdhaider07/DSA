#include <bits/stdc++.h>

using namespace std;

// feinacci function
int fibonacci(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int fib2(int n, int *arr)
{
    if (n == 1)
    {
        return n;
    }
    if (n <= 0)
    {
        return 0;
    }

    if (arr[n] != 0)
    {
        return arr[n];
    }
    int output = fib2(n - 1, arr) + fib2(n - 2, arr);
    arr[n] = output;

    return arr[n];
}

int fib3(int n)
{
    int *arr = new int[n + 1];
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    int output = arr[n];
    delete[] arr;
    return arr[n];
}

// all the permutation of the string

string permutationAll(string str, int i, int m)
{
    int n = str.size();
    if (m - 1 == i)
    {
        return str[i] + "";
    }
    if (i >= m)
    {
        return "";
    }

    string temp = str;
    temp = temp.substr(0, i) + temp.substr(i + 1, n);
    cout << temp << endl;
    string s = str[i] + permutationAll(temp, i + 1, m);

    cout << s;
    return s;
}

int main()
{
    permutationAll("abs", 0, 3);

    return 0;
}