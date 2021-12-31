#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n, ans = 0;
    cin >> n;
    while (n > 0)
    {
        ans++;
        n = n & (n - 1);
    }
    cout << ans;
    return 0;
}