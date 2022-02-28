class Solution
{
public:
    vector<int> verticalSum(Node *root)
    {
        vector<int> ans;
        map<int, vector<int>> mp;
        if (!root)
            return ans;
        queue<pair<Node *, int>> q;
        q.push(make_pair(root, 0));

        while (!q.empty())
        {
            int s = q.size();
            for (int i = 0; i < s; i++)
            {
                auto tmp = q.front();
                q.pop();
                if (tmp.first->left)
                    q.push({tmp.first->left, tmp.second - 1});
                if (tmp.first->right)
                    q.push({tmp.first->right, tmp.second + 1});

                mp[tmp.second].push_back(tmp.first->data);
            }
        }
        for (auto i : mp)
        {
            int sum = 0;
            for (auto j : i.second)
                sum += j;

            ans.push_back(sum);
        }
        return ans;
    }
};