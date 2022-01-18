class Solution
{

public:
    vector<int> downwardDigonal(int n, vector<vector<int>> A)
    {
        // Your code goes here
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            int c = i, r = 0;
            while (c >= 0 && r < n)
            {
                ans.push_back(A[r++][c--]);
            }
        }
        for (int i = 1; i < n; i++)
        {
            int r = i, c = n - 1;
            while (c >= 0 && r < n)
            {
                ans.push_back(A[r++][c--]);
            }
        }

        return ans;
    }
};
