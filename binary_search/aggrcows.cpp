#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define For(i, n) for (int i = 0; i < n; i++)
using namespace std;
// https://www.spoj.com/problems/AGGRCOW/

bool canBeStalled(vector<int> &v, int min_distance, int cows)
{
    
    int last = v[0], n = v.size();
    cows--;
    for (int i = 1; i < n; i++)
    {
        if (v[i] - last >= min_distance)
        {
            last = v[i];
            cows--;
        }
        if (cows == 0)
            break;
    }

    return (cows == 0);
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
        int n, c;
        cin >> n >> c;
        vector<int> stalls(n);
        for (int &i : stalls)
            cin >> i;
        sort(stalls.begin(), stalls.end());
        int low = 1, right = 1e9, mid, ans;
        while (low <= right)
        {
            mid = low + (right - low) / 2;
            if (canBeStalled(stalls, mid, c))
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}