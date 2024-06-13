#include <iostream>
#include <vector>

using namespace std;

// swap sort for find missing value and doublicant 1 to N numbers

void swapsort(vector<int> &v)
{

    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        if ((v[i] - 1) != i)
        {
            if (v[i] == v[v[i] - 1])
            {
                cout << "missing element " << i + 1 << "Dublicate lement : " << v[i];
            }
            else
            {
                while (v[i] != v[v[i] - 1])
                {
                    swap(v[i], v[v[i] - 1]);
                }
            }
        }
    }

    for (auto i : v)
    {
        cout << i << " ";
    }
}

int main()
{
    vector<int> v{1, 2, 4, 2, 5};
    swapsort(v);

    cout << "\ncode excecuted success";
    return 0;
}