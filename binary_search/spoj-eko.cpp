#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define For(i, n) for (int i = 0; i < n; i++)
using namespace std;
// predicate binary search
// https://www.spoj.com/problems/EKO/
bool requirement_reached(vector<int> &v, ll m, int h)
{
    ll collected = 0;
    int n = v.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if (v[i] > h)
        {
            collected += v[i] - h;
            if (collected >= m)
                return true;
        }
        else
            break;
    }
    return false;
}

int main()
{
    //#ifndef ONLINE_JUGDE
    //    freopen("intput.txt","r",stdin);
    //    freopen("output.txt","w",stdout);
    //#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    ll m;
    cin >> n >> m;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;
    sort(v.begin(), v.end());
    int low = 1, hi = v[n - 1], mid, ans;
    while (low <= hi)
    {
        mid = low + (hi - low) / 2;
        if (requirement_reached(v, m, mid))
        {
            ans = mid;
            low = mid + 1;
        }
        else
            hi = mid - 1;
    }

    cout << ans;
    return 0;
}