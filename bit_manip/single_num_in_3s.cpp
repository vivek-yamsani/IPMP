#include <iostream>
#include <string>
#include <vector>
using namespace std;

int singleNumber(const vector<int> &A)
{
    // unordered_map<int, int> v;
    // for (int i : A)
    //     v[i]++;
    // for (int i : A)
    //     if (v[i] == 1)
    //         return i;

    // if x has 0 at position then zeros will be 3x+1 at positon else 1
    int count = 0, ans = 0;
    for (int i = 0; i < 31; i++)
    {
        for (int j : A)
        {
            if (j & (1 << i))
                count++;
        }
        int x = count % 3;
        ans = (ans | (x << i));
        count = 0;
    }

    return ans;
}

int main()
{
    cout << singleNumber({1, 2, 4, 3, 3, 2, 2, 3, 1, 1});
    return 0;
}