int bitonic(vector<int> arr, int n)
{
    // code here
    int j = 0;
    int st = 0, next_start = 0, ans = 1;
    while (j < n - 1)
    {
        while (j < n - 1 && arr[j] <= arr[j + 1])
        {
            j++;
        }
        while (j < n - 1 && arr[j] >= arr[j + 1])
        {
            if (arr[j] > arr[j + 1])
                next_start = j + 1;

            j++;
        }

        ans = max(ans, j - st + 1);
        st = next_start;
    }

    return ans;
}