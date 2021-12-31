#include <iostream>
#include <string>
#include <vector>
using namespace std;

int sum(int a, int b)
{
    int carry = 0, ans = 0;
    for (int i = 0; i < 31; i++)
    {
        int x = a & (1 << i), y = b & (1 << i);
        carry = (carry & (x ^ y)) | (x & y);
        ans = ans | ((carry ^ x ^ y) & (1 << i));
    }

    return ans;
}

int main()
{
    cout << sum(1025, 10);
    return 0;
}