#include <iostream>
#include <string>
#include <vector>
using namespace std;

int findUnsortedSubarray(vector<int> &nums)
{
    int n = nums.size(), s = 0, e = n - 1;
    if (n == 0)
        return 0;
    while (s < n - 1)
    {
        if (nums[s] > nums[s + 1])
            break;
        s++;
    }
    if (s == n - 1)
        return 0;
    while (e > 0)
    {
        if (nums[e] < nums[e - 1])
            break;
        e--;
    }
    int max = INT_MIN, min = INT_MAX;
    for (int i = s; i <= e; i++)
    {
        max = max > nums[i] ? max : nums[i];
        min = min < nums[i] ? min : nums[i];
    }
    for (int i = 0; i < s; i++)
    {
        if (nums[i] > min)
        {
            s = i;
            break;
        }
    }
    for (int i = n - 1; i > e; i--)
    {
        if (nums[i] < max)
        {
            e = i;
            break;
        }
    }
    return e - s + 1;
}

int main()
{
    vector<int> v = {2,6,4,8,10,9,15};
    cout<<findUnsortedSubarray(v);
    return 0;
}