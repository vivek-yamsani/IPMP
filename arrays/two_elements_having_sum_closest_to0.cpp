class Solution
{
public:
    static bool compare(int x, int y)
    {
        return abs(x) < abs(y);
    }
    int closestToZero(int a[], int n)
    {
        // your code here
        sort(a, a + n, compare);
        int ans = INT_MAX;
        for (int i = 1; i < n; i++)
        {
            if (abs(ans) > abs(a[i] + a[i - 1]))
                ans = a[i] + a[i - 1];
            else if (abs(ans) == abs(a[i] + a[i - 1]))
                ans = max(ans, a[i] + a[i - 1]);
        }

        return ans;
    }
};