// with duplicates
int findMin(vector<int> &arr)
{
    int n = arr.size(), i = 0, j = n - 1;
    while (i < j)
    {
        int mid = i + (j - i) / 2;
        if (arr[mid] > arr[j])
            i = mid + 1;
        else if (arr[mid] < arr[j])
            j = mid;
        else
            j--;
    }

    return arr[j];
}