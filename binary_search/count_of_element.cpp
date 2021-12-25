#include <iostream>
#include <string>
#include <vector>
using namespace std;

int count(int a[], int n, int x)
{
    // code here
    int st = 0, end = n - 1, lower, upper, mid;
    while (st < end)
    {
        mid = (end - st) / 2 + st;
        if (a[mid] >= x)
            end = mid;
        else
            st = mid + 1;
    }
    if (a[end] != x)
        return 0;
    lower = end;

    st = 0, end = n - 1;
    while (st < end)
    {
        mid = (end - st) / 2 + st;
        if (a[mid] <= x)
            st = mid + 1;
        else
            end = mid;
    }
    if (a[st] == x)
        st++;
    upper = st - 1;
    return upper - lower + 1;
}

int main()
{
    int arr[] = {8, 9, 10, 12, 12, 12};
    cout << count(arr, 6, 12);
    return 0;
}