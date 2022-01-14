#include <iostream>
#include <string>
#include <vector>
using namespace std;

// finding row with max_no_of ones in 0,1 sorted 2D array
int lower_bound(vector<int> v, int st, int end, int tar)
{
    if (st > end || st == end && tar != v[st])
        return -1;
    if (st == end && v[st] == tar)
        return st;
    int mid = st + (end - st) / 2;
    if (v[mid] >= tar)
        return lower_bound(v, st, mid, tar);
    else
        return lower_bound(v, mid + 1, end, tar);
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    for (auto &i : v)
    {
        for (auto &j : i)
            cin >> j;
    }
    int max_so_far = INT_MIN, ans = 0, co = 0;
    for (auto i : v)
    {
        co++;
        int first = ::lower_bound(i, 0, n - 1, 1);
        if (first > -1 && max_so_far < n - first)
        {
            ans = co;
            max_so_far = max(n - first, max_so_far);
        }
    }
    cout << ans;
    return 0;
}