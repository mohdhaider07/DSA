// cpp startar code
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>

using namespace std;

bool ispar(string x)
{
    stack<char> s;

    for (int i = 0; i < x.size(); i++)
    {
        if (x[i] == '(' || x[i] == '{' || x[i] == '[')
        {
            s.push(x[i]);
        }
        else
        {
            if (s.empty())
            {
                return false;
            }
            if (x[i] == ')')
            {
                char top = s.top();
                if (top == '(')
                {
                    s.pop();
                    continue;
                }
                return false;
            }
            if (x[i] == ']')
            {
                char top = s.top();
                if (top == '[')
                {
                    s.pop();
                    continue;
                }
                return false;
            }
            if (x[i] == '}')
            {
                char top = s.top();
                if (top == '{')
                {
                    s.pop();
                    continue;
                }
                return false;
            }
        }
    }

    // Your code here
    return s.empty();
}

int peakElement(int arr[], int n)
{
    // Your code here
    if (n == 1)
    {
        return 0;
    }
    if (arr[0] >= arr[1])
    {
        return 0;
    }
    if (arr[n - 1] >= arr[n - 2])
    {
        return n - 1;
    }

    int left = 1;
    int right = n - 2;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] >= arr[mid + 1] && arr[mid] >= arr[mid - 1])
        {
            return mid;
        }
        // if ans is in left side
        if (arr[mid] <= arr[mid - 1])
        {
            right = mid - 1;
        }
        else if (arr[mid] <= arr[mid + 1])
        {
            left = mid + 1;
        }
    }
    return -1;
}

// ke pair
bool hasArrayTwoCandidates(int arr[], int n, int x)
{
    // sort arr
    sort(arr, arr + n);
    int i = 0;
    int j = n - 1;
    while (i <= j)
    {
        int sum = arr[i] + arr[j];

        if (sum == x)
        {
            return true;
        }
        if (sum > x)
        {
            j--;
            continue;
        }
        i++;
    }

    return false;
}

int remove_duplicate(int a[], int n)
{
    // code here
    if (n < 2)
    {
        return n;
    }
    int j = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[j] != a[i])
        {
            j++;         // Move to the next position
            a[j] = a[i]; // Update the position with the current element
        }
    }
    return j + 1;
}
int main()
{
    cout << "Hello World\n";
    cout << ispar("{([])}");
    return 0;
}