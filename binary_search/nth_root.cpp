#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

double eps = 1e-6;

double multiply(double x, int n)
{
    double ans = 1;
    for (int i = 0; i < n; i++)
        ans *= x;
    return ans;
}

double nth_root(double x, int n)
{
    double low = 1, hi = x, mid;
    while (hi - low > eps)
    {
        mid = (hi + low) / 2;
        if (multiply(mid, n) < x)
            low = mid;
        else
            hi = mid;
    }

    return low;
}
// N for multiply function * Log(N*10^d) => 10^d no's in i to i+1

int main()
{
    cout << fixed << setprecision(10) << nth_root(27, 3);
    return 0;
}