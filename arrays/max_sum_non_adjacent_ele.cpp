int findMaxSum(int *arr, int n)
{
    // code here
    if (n == 1)
    {
        return arr[0];
    }
    else if (n == 2)
    {
        return max(arr[0], arr[1]);
    }
    else
    {
        // max of n = max(max of n-1,max of n-2 + arr[n]);
        int dp[n] = {0};
        dp[0] = arr[0];
        dp[1] = max(arr[0], arr[1]);
        dp[2] = max(dp[1], dp[0] + arr[2]);
        for (int i = 3; i < n; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]);
        }

        return dp[n - 1];
    }
}