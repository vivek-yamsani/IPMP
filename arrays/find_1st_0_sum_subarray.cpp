class Solution
{
public:
    // Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n)
    {
        // code here
        unordered_map<int, vector<int>> m;
        ll ans = 0, sum = 0;
        for (ll i : arr)
        {
            sum += i;
            if (sum == 0)
                ans++;
            if (m.find(sum) != m.end())
            {
                ans += m[sum].size();
            }
            m[sum].push_back(1);
        }

        return ans;
    }
    // 10 6 -1 -3 4 -2 2 4 6 -12 -7
};

pair<int, int> first_subarray(vector<ll> arr, int n)
{
    unordered_map<int, int> m;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0)
            return {0, i};
        if (m.find(sum) != m.end())
        {
            return {m[sum], i};
        }

        m[sum] = i;
    }

    return {-1, -1};
}