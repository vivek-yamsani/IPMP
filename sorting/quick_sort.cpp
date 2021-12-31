#include <iostream>
#include <string>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int low, int high)
{
    int pivot = low, i = low, j = high, n = arr.size();
    while (i <= j)
    {
        while (i < n && arr[i] <= arr[pivot])
            i++;
        while (j >= 0 && arr[j] > arr[pivot])
            j--;
        if (i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[pivot];
    arr[pivot] = arr[j];
    arr[j] = temp;

    return j;
}

void quick_sort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;
    int pivot = partition(arr, low, high);
    quick_sort(arr, low, pivot - 1);
    quick_sort(arr, pivot + 1, high);
}

int main()
{
    vector<int> v = {5, 4, 3, 2, 1};
    quick_sort(v, 0, 4);
    for (int i : v)
        cout << i << " ";
    return 0;
}