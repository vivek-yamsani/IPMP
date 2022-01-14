#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int no_of_triplets(int n)
{
    int ans = 0;
    for (long long a = 1; a <= n; a++)
    {
        for (long long b = a; b <= n; b++)
        {
            long long c2 = a * a + b * b;
            long long c = sqrt(c2);
            if (c <= n && c * c == c2)
            {
                cout << a << " " << b << " " << c << "\n";
                ans++;
            }
        }
    }

    return ans;
}

int main()
{
    cout << no_of_triplets(5);
    return 0;
}