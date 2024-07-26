#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxMeetings(int s[], int e[], int n)
{
    vector<pair<int, int>> meet(n);

    for (int i = 0; i < n; i++)
    {
        meet[i] = {e[i], s[i]};
    }

    // Sort meetings based on end time
    sort(meet.begin(), meet.end());

    int count = 1;
    int endTime = meet[0].first;
    for (int i = 1; i < n; i++)
    {
        if (endTime < meet[i].second)
        {
            endTime = meet[i].first;
            count++;
        }
    }

    return count;
}

int findPlatform(int arr[], int dep[], int n)
{
    // Your code here
    vector<pair<int, char>> train;
    for (int i = 0; i < n; i++)
    {
        train.push_back({arr[i], 'A'});
        train.push_back({dep[i], 'D'});
    }

    sort(train.begin(), train.end());

    int count = 0;
    int maxCount = 0;

    for (int i = 0; i < train.size(); i++)
    {
        pair<int, char> thisTrain = train[i];
        int time = thisTrain.first;
        char ad = thisTrain.second;

        if (ad == 'A')
        {
            count++;
            maxCount = max(maxCount, count);
        }
        else
        {
            count--;
        }
    }

    return maxCount;
}

// (1,4,20),(2,1,10),(3,1,40),(4,1,30)
struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

bool comparator(pair<int, int> &lhs, pair<int, int> &rhs)
{
    if (lhs.first < rhs.first)
    {
        // Sort in ascending order of deadline
        return true;
    }
    else if (lhs.first == rhs.first)
    {
        // If deadlines are the same, sort in descending order of profit
        return lhs.second > rhs.second;
    }
    return false;
}
vector<int> JobScheduling(Job arr[], int n)
{
    // your code here
    // vector will store {dealdile , profit}
    vector<pair<int, int>> jobs;
    for (int i = 0; i < n; i++)
    {
        jobs.push_back({arr[i].dead, arr[i].profit});
    }
    // PRINT JOBS VECTOR
    for (int i = 0; i < jobs.size(); i++)
    {
        cout << jobs[i].first << " " << jobs[i].second << endl;
    }
    // now i want to sort the vector like the dealdline which is smalest come first if the two jobs have the same deadline then the job which will come first which will have the highest profit
    sort(jobs.begin(), jobs.end(), comparator);
    // PRINT JOBS VECTOR AFTER SORTING
    for (int i = 0; i < jobs.size(); i++)
    {
        cout << jobs[i].first << " " << jobs[i].second << endl;
    }
    int profitSum = jobs[0].second;
    int jobCount = 1;
    int currentTime = jobs[0].first;
    for (int i = 1; i < jobs.size(); i++)
    {
        /* code */
        if (currentTime < jobs[i].first)
        {
            jobCount++;
            profitSum += jobs[i].second;
            currentTime = jobs[i].first;
        }
    }

    return {jobCount, profitSum};
}

struct Item
{
    int value;
    int weight;
};

double fractionalKnapsack(int w, Item arr[], int n)
{
    // Your code here
    vector<pair<int, pair<int, int>>> items;

    for (int i = 0; i < n; i++)
    {
        int fraction = arr[i].value / arr[i].weight;
        items.push_back({fraction, {arr[i].value, arr[i].weight}});
    }
    sort(items.begin(), items.end());

    double value = 0;

    for (int i = 0; i < n; i++)
    {
        if (items[i].second.second <= w)
        {
            value += items[i].second.first;
            w = w - items[i].second.second;
        }
        else if (w > 0)
        {
            value += items[i].first * w;
            w = 0;
        }
        else if (w == 0)
        {
            break;
        }
    }
    return value;
}

int findContentChildren(vector<int> &g, vector<int> &s)
{
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int j = 0;

    int count = 0;
    for (int i = 0; i < g.size(); i++)
    {
        bool flag = false;
        while (!flag && j < s.size())
        {
            if (s[j] >= g[i])
            {
                count++;
                j++;
                flag = true;
            }
            else
            {
                j++;
            }
        }
    }
}

int main()
{
    int s[] = {1, 3, 0, 5, 8, 5};
    int e[] = {2, 4, 10, 7, 9, 9};
    int n = sizeof(s) / sizeof(s[0]);
    cout << maxMeetings(s, e, n);

    cout << "\nGreedy from sde sheet of striver \n";

    return 0;
}