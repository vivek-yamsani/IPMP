#include <iostream>
#include <string>
#include <vector>
using namespace std;

int singleNumber(const vector<int> &A)
{
    int ans = 0;
    for (int i : A)
    {
        ans = ans ^ i;
    }
    return ans;
}

int main()
{
    cout<<singleNumber({1,2,3,2,1});
    return 0;
}