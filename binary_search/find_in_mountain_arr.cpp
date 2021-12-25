// Find the maximum element in an array which is first increasing and then decreasing
// ^ in pdf
int peakIndexInMountainArray(vector<int> &arr)
{
    int st = 0, end = arr.size() - 1, ans;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1])
        {
            ans = mid;
            break;
        }
        if (arr[mid] > arr[mid + 1])
            end = mid - 1;
        else
            st = mid + 1;
    }

    return ans;
}