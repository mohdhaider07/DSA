#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// finding the index of the minimum rotated array
void minInRotatedArray(vector<int> &arr)
{
    int n = arr.size();
    int s = 0;
    int e = n - 1;
    if (arr[0] <= arr[e])
    {
        cout << "min index" << 0;
        return;
    }
    while (s <= e)
    {
        int mid = (s + e) / 2;
        int prev = (mid + n - 1) % n;
        int next = (mid + 1) % n;
        if (arr[mid] <= arr[prev] && arr[mid] <= arr[next])
        {
            cout << "min index is" << mid;
            return;
        }

        if (arr[s] > arr[mid])
        {
            e = mid;
        }
        if (arr[e] < arr[mid])
        {
            s = mid + 1;
        }
    }
}

// normal binarry search
void BS(vector<int> arr, int target)
{
    int s = 0;
    int n = arr.size();
    int e = n - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == target)
        {
            cout << "index is : " << mid;
            return;
        }
        else if (
            target < arr[mid])
        {
            e = mid - 1;
        }
        else if (
            target > arr[mid])
        {
            s = mid + 1;
        }
    }
    cout << "No element found";
}

// Binarry search severse sorted array
void BS_reverce_sorted_array(vector<int> arr, int target)
{
    int n = arr.size();

    int s = 0;
    int e = n - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == target)
        {
            cout << "Target found " << mid;
            return;
        }
        else if (target < arr[mid])
        {
            s = mid + 1;
        }
        else if (target > arr[mid])
        {
            e = mid - 1;
        }
    }
    cout << "No found " << target;
}

// First and Last occurance in sorted array
int first_occurance(vector<int> arr, int target)
{
    int n = arr.size();
    int s = 0;
    int e = n - 1;
    int res = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == target)
        {
            res = mid;
            e = mid - 1;
        }
        else if (target < arr[mid])
        {
            e = mid - 1;
        }
        else if (target > arr[mid])
        {
            s = mid + 1;
        }
    }
    return res;
}

// last Occurance
int last_occurance(vector<int> arr, int target)
{
    int n = arr.size();
    int s = 0;
    int e = n - 1;
    int res = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (target == arr[mid])
        {
            res = mid;
            s = mid + 1;
        }
        else if (target > arr[mid])
        {
            s = mid + 1;
        }
        else if (target < arr[mid])
        {
            e = mid - 1;
        }
    }
    return res;
}

// count of an element is sorted array
void countArray(vector<int> arr, int target)
{
    int firstIndex = first_occurance(arr, target);
    int lastIndex = last_occurance(arr, target);
    cout << target << " No of Count : " << lastIndex - firstIndex + 1;
}
// searching in  nearly sorted array
// means the number can be present at ith index now it can found at i, i-1, i+1;

void SearchInNearly_sorted_arr(vector<int> arr, int target)
{
    int s = 0;
    int n = arr.size();
    int e = n - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == target)
        {
            cout << mid << endl;
            return;
        }
        else if (mid != 0 && arr[mid - 1] == target)
        {
            cout << mid - 1;
            return;
        }
        else if (mid != n - 1 && arr[mid + 1] == target)
        {
            cout << mid + 1;
            return;
        }
        else if (target > arr[mid])
        {
            s = mid + 2;
        }
        else if (target < arr[mid])
        {
            e = mid - 2;
        }
    }
    cout << "Element not fount : " << target;
}

// searching for floor of a number
int floor_of_number(vector<int> arr, int target)
{
    int n = arr.size();
    int s = 0;
    int e = n - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == target)
        {
            return arr[mid];
        }
        else if (arr[mid] < target)
        {
            s = mid + 1;
        }
        else if (arr[mid] > target)
        {
            e = mid - 1;
        }
    }
    return arr[e];
}

// searching roof of the element
int roof_of_number(vector<int> arr, int target)
{
    int n = arr.size();
    int s = 0, e = n - 1;
    while (s <= e)
    {
        /* code */
        int mid = s + (e - s) / 2;
        if (target == arr[mid])
        {
            return arr[mid];
        }
        else if (target > arr[mid])
        {
            s = mid + 1;
        }
        else if (target < arr[mid])
        {
            e = mid - 1;
        }
    }

    return arr[s];
}

char nextGreatestLetter(vector<char> &letters, char target)
{
    int n = letters.size();
    int s = 0;
    int e = n - 1;
    char ans = letters[0];
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (target < letters[mid])
        {
            ans = letters[mid];
            e = mid - 1;
        }
        else if (target >= letters[mid])
        {

            s = mid + 1;
        }
    }
    return ans;
}

// find first 1 in infinite sorted array
void fist_1_in_infinite_array(vector<int> &v, int target)
{
    int s = 0;
    int e = 1;
    int res = -1;
    while (v[e] < target)
    {
        s = e;
        e *= 2;
    }
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (target == v[mid])
        {
            e = mid - 1;
            res = mid;
        }
        else if (target > v[mid])
        {
            s = mid + 1;
        }
        else if (target < v[mid])
        {
            e = mid - 1;
        }
    }

    cout << "index is : " << res;
}

// find the minimum absolute difference in sorted array for taget is given
void minimum_absolute_diff(vector<int> &v, int target)
{
    int floor = floor_of_number(v, target);
    int ceil = roof_of_number(v, target);
    int floorDiff = std::abs((target - floor));
    int ceilDiff = std::abs((target - ceil));
    cout << (floorDiff > ceilDiff) ? ceilDiff : floorDiff;
}
// peak element this function is incompleate
// int findPeakElement(vector<int> &nums)
// {
//     int n = nums.size();
//     int s = 0;
//     int e = n - 1;
//     int ans = -1;
//     while (s <= e)
//     {
//         int mid = s + (e - s) / 2;
//         if (mid == 0 || mid == (n - 1) && nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1])
//         {
//             ans = mid;
//             break;
//         }
//         else if (nums[mid] > nums[mid + 1])
//         {
//             e = mid - 1;
//         }
//         else if (nums[mid] > nums[mid - 1])
//         {
//             s = mid + 1;
//         }
//     }
//     return ans;
// }

// peak element in bitonic array
int peakIndexInMountainArray(vector<int> &arr)
{
    int n = arr.size();
    int s = 0;
    int e = n - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        cout << "mid is " << mid << endl;
        if (mid != 0 && mid != n - 1 && arr[mid] >= arr[mid - 1] && arr[mid] >= arr[mid + 1])
        {
            return mid;
        }
        else if (mid == n - 1 || arr[mid] > arr[mid + 1])
        {
            e = mid - 1;
        }
        else if (mid == 0 || arr[mid] > arr[mid - 1])
        {
            s = mid + 1;
        }
    }
    return -1;
}

// searching element in bitonic array
int targetIndexInMountinArray(vector<int> &arr, int target)
{
    int s = 0;
    int n = arr.size();
    int e = n - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        cout << "mid is : " << mid << endl;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (mid != 0 && arr[mid - 1] == target)
        {
            return mid - 1;
        }
        else if (mid != n - 1 && arr[mid + 1] == target)
        {
            return mid + 1;
        }
        else if (mid == 0 || arr[mid - 1] > target)
        {
            s = mid + 1;
        }
        else if (mid == n - 1 || arr[mid + 1] > target)
        {
            e = mid - 1;
        }
    }
    return -1;
}
int main()
{
    vector<int> v{1, 2, 3, 4, 5, 3, 1};
    cout << targetIndexInMountinArray(v, 1);
    cout << "\nProgram excuted success fully";

    return 0;
}