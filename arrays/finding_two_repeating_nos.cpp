#include <iostream>
#include <string>
#include <vector>
using namespace std;
// n+2 --> elements   1...x...y....n x y

pair<int, int> repeating(vector<int> v, int n)
{
    int xr = 0;
    for (int i : v)
        xr ^= i;
    for (int i = 1; i <= n; i++)
    {
        xr ^= i;
    }
    int set_bit = xr & (~(xr - 1));
    pair<int, int> ans = {xr, xr};

    for (int i : v)
    {
        if (set_bit & i)
            ans.first ^= i;
        else
            ans.second ^= i;
    }
    for (int i = 1; i <= n; i++)
    {
        if (set_bit & i)
            ans.first ^= i;
        else
            ans.second ^= i;
    }

    return ans;
}

int main()
{
    pair<int, int> ans = repeating(vector<int>{4, 2, 4, 5, 2, 3, 1}, 5);
    cout << ans.first << " " << ans.second << "\n";
    return 0;
}