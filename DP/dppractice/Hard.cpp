//  boilar plate for cpp
#include <iostream>
#include <vector>

using namespace std;

int calculateSum(vector<int> &v)
{
    int sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        sum += v[i];
    }
    return sum;
}

int main()
{

    cout << "Hard Practice" << endl;
    return 0;
}