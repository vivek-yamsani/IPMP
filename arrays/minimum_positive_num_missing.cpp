#include <iostream>
#include <string>
#include <vector>
using namespace std;

int missing(vector<int> v, int n)
{
    int j = 0;
    for (int i = n - 1; i >= j; i--)
    {
        if (v[i] > 0)
        {
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
            j++;
            i++;
        }
    }

    for (int i = 0; i < j; i++)
    {
        if (abs(v[i]) - 1 < j && v[abs(v[i]) - 1] > 0)
            v[abs(v[i]) - 1] = -v[abs(v[i]) - 1];
    }

    for (int i = 0; i < j; i++)
    {
        if (v[i] > 0)
        {
            return i + 1;
        }
    }

    return j + 1;
}

int main()
{
    cout << missing(vector<int>{1, 1, 0, -1, -2}, 5);
    return 0;
}