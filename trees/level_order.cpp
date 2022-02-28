class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        queue<TreeNode *> q;
        vector<vector<int>> ans;

        if (root)
            q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++)
            {
                root = q.front();
                q.pop();
                if (root->left)
                    q.push(root->left);
                if (root->right)
                    q.push(root->right);

                level.push_back(root->val);
            }

            ans.push_back(level);
        }

        return ans;
    }
};