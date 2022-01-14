vector<int> duplicates(int arr[], int n)
{
    // code here
    for (int i = 0; i < n; i++)
    {
        arr[arr[i] % n] += n;
    }
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] / n > 1)
            ans.push_back(i);
    }
    if (ans.size() == 0)
        return {-1};
    return ans;
}
