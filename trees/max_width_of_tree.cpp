class Solution
{
public:
    // Function to get the maximum width of a binary tree.
    int getMaxWidth(Node *root)
    {

        if (!root)
            return 0;
        // Your code here
        queue<Node *> q;
        q.push(root);
        int ans = 1;
        while (!q.empty())
        {
            int size = q.size();
            int nodes = 0;
            for (int i = 0; i < size; i++)
            {
                Node *tmp = q.front();
                q.pop();

                if (tmp->left)
                {
                    nodes++;
                    q.push(tmp->left);
                }
                if (tmp->right)
                {
                    nodes++;
                    q.push(tmp->right);
                }
            }
            ans = max(nodes, ans);
        }

        return ans;
    }
};