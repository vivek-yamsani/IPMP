#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
void merge(vector<int> &arr, int l, int mid, int r)
{
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

void mergesort(vector<int> &arr, int l, int r)
{
    if (l == r)
        return;
    int mid = l + (r - l) / 2;
    mergesort(arr, l, mid);
    mergesort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}

vector<int> sortArray(vector<int> &nums)
{
    mergesort(nums, 0, nums.size() - 1);
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