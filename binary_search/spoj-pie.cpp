#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <math.h>
#define ll long long int
#define mod 1000000007
#define For(i, n) for (int i = 0; i < n; i++)
using namespace std;

// https://www.spoj.com/problems/PIE/

double eps = 1e-5;

bool isPossible(vector<long double> &pie,long double vol, int f)
{
    for (int i = pie.size() - 1; i >= 0; i--)
    {
        if (pie[i] >= vol)
        {
            f -= (int)(pie[i] / vol);
            if (f <= 0)
                break;
        }
        else
            break;
    }
    return (f <= 0);
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
        int n, f;
        cin >> n >> f;
        f++;
        vector<long double> vol(n);
        for (long double &i : vol)
        {
            cin >> i;
            i *= i;
            i = M_PI * i;
        }
        sort(vol.begin(), vol.end());
        long double low = 0, hi = vol[n - 1], mid, ans;
        while (hi - low >= eps)
        {
            mid = low + (hi - low) / 2;
            if (isPossible(vol, mid, f))
            {
                ans = mid;
                low = mid;
            }
            else
            {
                hi = mid;
            }
        }
        cout << fixed << setprecision(4) << mid << "\n";
    }

    return 0;
}