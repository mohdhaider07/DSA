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
#include <climits>

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
            j++; // Move to the next position
        }
        a[j] = a[i]; // Update the position with the current element
    }
    return j + 1;
}

bool areIsomorphic(string str1, string str2)
{

    int n = str1.size();
    int m = str2.size();
    if (n != m)
    {
        return false;
    }

    vector<int> v1(26, -1);
    vector<int> v2(26, -1);

    for (int i = 0; i < n; i++)
    {
        int ss = str1[i] - 'a';
        int tt = str2[i] - 'a';

        if (v1[ss] == -1 && v2[tt] == -1)
        {
            v1[ss] = tt;
            v2[tt] = ss;
        }
        else if (v1[ss] != tt || v2[tt] != ss)
        {
            return false;
        }
    }
    return true;

    // Your code here
    return true;
}

int smallestSubWithSum(int arr[], int n, int x)
{
    // Your code goes here
    int minSize = INT_MAX;
    int start = 0;
    int currentSum = 0;

    for (int end = 0; end < n; end++)
    {
        // Add current element to currentSum
        currentSum += arr[end];

        // While currentSum is greater than x, try to minimize the window
        while (currentSum > x)
        {
            minSize = min(minSize, end - start + 1);
            currentSum -= arr[start];
            start++;
        }
    }

    // If minSize wasn't updated, return 0 to indicate no valid subarray was found
    return (minSize == INT_MAX) ? 0 : minSize;
}

long long firstIndex(vector<long long> v, long long x, long long n)
{

    long long start = 0;
    long long end = n - 1;
    long long index = INT_MAX;
    while (start <= start)
    {
        long long mid = (start + end) / 2;
        if (v[mid] == x)
        {
            index = min(index, mid);
        }
        if (v[mid] < x)
        {
            start = mid + 1;
        }
        if (v[mid] >= x)
        {
            end = mid - 1;
        }
    }

    return index == INT_MAX ? -1 : index;
}
long long lastIndex(vector<long long> v, long long x, long long n)
{

    long long start = 0;
    long long end = n - 1;
    long long index = INT_MIN;
    while (start <= start)
    {
        long long mid = (start + end) / 2;
        if (v[mid] == x)
        {
            index = max(index, mid);
        }
        if (v[mid] <= x)
        {
            start = mid + 1;
        }
        if (v[mid] > x)
        {
            end = mid - 1;
        }
    }

    return index == INT_MIN ? -1 : index;
}

bool areKAnagrams(string str1, string str2, int k)
{
    // code here
    int n = str1.size();
    int m = str2.size();
    if (n != m)
        return false;

    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    cout << str1 << " " << str2 << endl;

    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (str1[i] != str2[i])
        {
            break;
        }
        c++;
    }

    cout << "coutn tis " << c << endl;
    return (c + k - n) >= 0 ? true : false;
}

long long int countStrHelper(long long int n, int b, int c)
{
    if (n == 1)
    {
        if (b > 0 && c > 0)
        {
            return 3;
        }
        if (b > 0 || c > 0)
        {
            return 2;
        }
        return 1;
    }
    int ans = 0;
    // if b is allowyed
    if (b > 0)
    {
        ans += countStrHelper(n - 1, b - 1, c);
    }
    if (c > 0)
    {
        ans += countStrHelper(n - 1, b, c - 1);
    }

    ans += countStrHelper(n - 1, b, c);

    return ans;
}

long long int
countStr(long long int n)
{
    // complete the function here
    return countStrHelper(n, 1, 2);
}

void generate_binary_string_helper(string s, int i, string str, vector<string> &ans)
{
    int n = s.size();
    if (i >= n)
    {
        ans.push_back(str);
    }

    for (i; i < n; i++)
    {
        if (s[i] == '?')
        {
            break;
        }
        str = str + s[i];
    }

    if (s[i] == '?')
    {
        generate_binary_string_helper(s, i + 1, str + '0', ans);
        generate_binary_string_helper(s, i + 1, str + '1', ans);
    }
}

vector<string> generate_binary_string(string s)
{
    // Code here
    vector<string> ans;
    generate_binary_string_helper(s, 0, "", ans);

    return ans;
}

int main()
{
    cout << "Hello World\n";
    cout << countStr(3) << endl;

    return 0;
}