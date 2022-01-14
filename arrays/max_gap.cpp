#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;

    int small = v[0], ans = 0;
    for (int i : v)
    {
        ans = max(i - small, ans);
        small = min(small, i);
    }
    cout << ans << "\n";
    return 0;
}
// 2, 3, 10, 6, 4, 8, 1