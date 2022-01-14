#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define For(i, s, n) for (int i = s; i < n; i++)
using namespace std;

bool isPossible(vector<int> &v, int m, int k)
{
    int days = 0;
    for (int i : v)
    {
        if (i <= k)
            days++;
        if (i > k)
        {
            days += ceil((double)i / (double)k);
        }
    }

    return (days <= m);
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
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> b(n);
        For(i, 0, n) cin >> b[i];
        int low = 1, hi = 1e9 + 1, ans, mid;
        while (low <= hi)
        {
            mid = low + (hi - low) / 2;
            if (isPossible(b, m, mid))
            {
                ans = mid;
                hi = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}