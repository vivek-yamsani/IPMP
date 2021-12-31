#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int ans = 0, ex = 1;
    // for (int i = 0; i < 32; i++)
    // {
    //     if ((a & ex) != (b & ex))
    //         ans++;
    //     ex = ex << 1;
    // }
    // O(n)
    int xr = a ^ b;
    while (xr)
    {
        ans++;
        xr = (xr & (xr - 1));
    }
    // O(no of flips)
    cout << ans << "\n";
    return 0;
}