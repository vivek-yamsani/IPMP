#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solve(int A)
{
    vector<int> v(31, 0);
    for (int i = 1; i < 31; i++)
    {
        int ex = 1 << i;
        v[i - 1] += ((A + 1) / ex) * (ex / 2);
        v[i - 1] += ((A + 1) % ex > ex / 2 ? (((A + 1) % ex) - (ex / 2)) : 0);
    }

    int mod = (int)(1e9 + 7);
    int sum = 0;
    for (int i : v)
    {
        sum += i;
        sum = sum % mod;
    }

    return sum;
}

int main()
{
    cout << solve(3);
    return 0;
}