#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int ans = 0, pos = n & (~(n - 1));
    while (pos)
    {
        ans++;
        pos >>= 1;
    }
    cout << ans << "\n";
    return 0;
}