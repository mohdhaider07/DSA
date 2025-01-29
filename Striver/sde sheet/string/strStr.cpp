#include <iostream>
#include <string>
using namespace std;
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        
        // If needle is longer than haystack, return -1
        if (m > n) return -1;

        // Sliding window approach
        for (int i = 0; i <= n - m; i++) {
            int j = 0;
            while (j < m && haystack[i + j] == needle[j]) {
                j++;
            }
            if (j == m) return i; // Found match
        }
        
        return -1; // No match found
    }

int main()
{

    cout << "strStr";
    return 0;
}