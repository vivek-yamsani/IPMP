#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    unsigned int n;
    cin >> n;
    unsigned int ans = 0;
    int ex = 1;
    for (int i = 0; i < 32; i++)
    {
        if (ex & n)
        {
            ans = (ans | (1 << (31 - i)));
        }
        ex = ex << 1;
    }
    // O(n) n -> no of bits

    cout << ans << "\n";
    return 0;
}