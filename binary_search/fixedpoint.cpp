#include <iostream>
#include <string>
#include <vector>
using namespace std;

int fixedPoint(int arr[], int n)
{
    int st = 0, end = n - 1, mid;
    while (st <= end)
    {
        mid = (end - st) / 2 + st;
        if (arr[mid] == mid)
            return mid;
        if (arr[mid] > mid)
            end = mid - 1;
        else
            st = mid + 1;
    }

    return -1;
}

int main()
{

    int arr[] = {0, 2, 5, 8, 17};
    cout << fixedPoint(arr, 5);
    return 0;
}