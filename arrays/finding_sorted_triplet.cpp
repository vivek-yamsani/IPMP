#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <climits>
using namespace std;

tuple<int, int, int> triplet(vector<int> v, int n)
{
    vector<int> large(n, INT_MIN), small(n, INT_MAX);
    small[0] = v[0];
    large[n - 1] = v[n - 1];
    for (int i = 1; i < n - 1; i++)
    {
        small[i] = min(small[i - 1], v[i - 1]);
        large[n - i - 1] = max(large[n - i], v[n - i]);
    }
    for (int i = 1; i < n - 1; i++)
    {
        if (small[i] < v[i] && large[i] > v[i])
        {
            return make_tuple(small[i], v[i], large[i]);
        }
    }
    return make_tuple(-1, -1, -1);
}

int main()
{
    tuple<int, int, int> ans = triplet(vector<int>{1, 2, 3, 4}, 4);
    cout << get<0>(ans) << " " << get<1>(ans) << " " << get<2>(ans);
    return 0;
}