class Solution
{
public:
    void leftBoundary(Node *root, vector<int> &ans)
    {
        if (!root)
            return;

        if (root->left)
        {
            ans.push_back(root->data);
            leftBoundary(root->left, ans);
        }
        else if (root->right)
        {
            ans.push_back(root->data);
            leftBoundary(root->right, ans);
        }
    }

    void rightBoundary(Node *root, vector<int> &ans)
    {
        if (!root)
            return;

        if (root->right)
        {
            rightBoundary(root->right, ans);
            ans.push_back(root->data);
        }
        else if (root->left)
        {
            rightBoundary(root->left, ans);
            ans.push_back(root->data);
        }
    }

    void leaves(Node *root, vector<int> &ans)
    {
        if (!root)
            return;

        leaves(root->left, ans);

        if (!root->left && !root->right)
            ans.push_back(root->data);

        leaves(root->right, ans);
    }

    vector<int> boundary(Node *root)
    {
        // Your code here
        vector<int> ans;
        ans.push_back(root->data);

        leftBoundary(root->left, ans);

        leaves(root->left, ans);
        leaves(root->right, ans);

        rightBoundary(root->right, ans);

        return ans;
    }
};