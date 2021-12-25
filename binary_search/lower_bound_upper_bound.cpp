#include <iostream>
#include <string>
#include <vector>
using namespace std;

int lower_bound(vector<int> a, int n, int key)
{
    int s = 0, e = n - 1, mid;
    while (s < e)
    {
        mid = s + (e - s) / 2;
        if (a[mid] >= key)
            e = mid;
        else
            s = mid + 1;
    }
    return e;
}

int upper_bound(vector<int> v, int n, int key)
{
    if (n == 0)
        return -1;
    int s = 0, e = n - 1, mid;
    while (s < e)
    {
        mid = s + (e - s) / 2;
        if (v[mid] <= key)
            s = mid + 1;
        else
            e = mid;
    }
    return e;
}

int main()
{
    vector<int> v = {2, 4, 8, 10, 10, 10, 18, 20};
    cout << lower_bound(v, 8, 10) << " " << upper_bound(v, 8, 10);
    return 0;
}