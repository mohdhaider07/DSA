#include <bits/stdc++.h>
using namespace std;

// find n to 1 in minum steps
// n-1, n/2 if(n%2==0), n/3if(n%3==0)

// int find_min_steps(int n)
// {
//     if (n == 1)
//     {
//         return 0;
//     }
//     int x = find_min_steps(n - 1);
//     int y = INT_MAX;
//     int z = INT_MAX;
//     if (n % 2 == 0)
//     {
//         y = find_min_steps(n / 2);
//     }
//     if (n % 3 == 0)
//     {
//         z = find_min_steps(n / 3);
//     }
//     return min(x, min(x, y)) + 1;
// }

// Dynamic program for Minimun steps to 1
int find_min_steps(int n)
{
    int *arr = new int[n + 1];
    arr[0] = 0;
    arr[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        int x = arr[i - 1];
        int y = INT_MAX;
        int z = INT_MAX;
        if (i % 2 == 0)
        {
            y = arr[i / 2];
        }
        if (i % 3 == 0)
        {
            z = arr[i / 3];
        }
        arr[i] = min(x, min(y, z)) + 1;
    }
    int output = arr[n];
    delete[] arr;
    return output;
}

int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;
    int *arr = new int[n];
    // initialize array with -1
    for (int i = 0; i < n; i++)
    {
        arr[i] = -1;
    }

    // travering array for loop
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "Minimun numbers of steps: " << find_min_steps(n);
    return 0;
}