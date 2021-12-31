#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> count_sort(vector<int> arr)
{
    vector<int> a((int)1e9, 0), ans(arr.size());
    for (int i : arr)
        a[i]++;
    for (int i = 1; i <= (int)1e9; i++)
    {
        a[i] += a[i - 1];
    }
    for (int i : arr)
    {
        ans[--a[i]] = i;
    }

    return ans;
}

int main()
{
    vector<int> v = {5, 4, 3, 2, 1};
    vector<int> ans = count_sort(v);
    for (int i : ans)
        cout << i << " ";
    return 0;
}