#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
void merge(vector<int> &arr, int l, int mid, int r)
{

    if (l == r)
        return;
    int i = 0, j = 0, k = l;
    vector<int> left, right;
    for (int i = l; i <= mid; i++)
        left.push_back(arr[i]);
    for (int i = mid + 1; i <= r; i++)
        right.push_back(arr[i]);
    int n = left.size(), m = right.size();
    while (i < n && j < m)
    {
        if (left[i] < right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }
    while (i < n)
        arr[k++] = left[i++];
    while (j < m)
        arr[k++] = right[j++];
}

vector<int> sortArray(vector<int> &nums)
{
    int n = nums.size();
    if (n <= 1)
        return nums;
    for (int size = 2; size < 2*n; size *= 2)
    {
        for (int left = 0; left < n; left += size)
        {
            int mid = min((left + (size / 2) - 1), n - 1);
            int right = min(left + size - 1, n - 1);

            merge(nums, left, mid, right);
        }
    }
    return nums;
}

int main()
{
    vector<int> v = {5, 4, 3, 2, 1};
    vector<int> ans = sortArray(v);
    for (int i : ans)
        cout << i << " ";
    return 0;
}