class Solution
{
public:
    /*You are required to complete this method*/
    unordered_map<Node *, int> mp;
    int height(Node *root)
    {
        if (!root)
            return 0;
        if (mp[root])
            return mp[root];
        return mp[root] = 1 + max(height(root->left), height(root->right));
    }
    bool check(Node *root)
    {
        // Your code here
        if (!root)
            return 1;
        if (root->left == NULL && root->right == NULL)
            return 1;
        if (root->left == NULL)
            return check(root->right);
        if (root->right == NULL)
            return check(root->left);

        if (height(root->left) == height(root->right))
            return (check(root->left) && check(root->right));

        return 0;
    }
};

bool checkUtil(struct Node *root, int level, int *leafLevel)
{
    if (root == NULL)
        return true;

    if (root->left == NULL &&
        root->right == NULL)
    {
        if (*leafLevel == 0)
        {
            *leafLevel = level;
            return true;
        }
        return (level == *leafLevel);
    }

    return checkUtil(root->left, level + 1, leafLevel) && checkUtil(root->right, level + 1, leafLevel);
}

bool check(struct Node *root)
{
    int level = 0, leafLevel = 0;
    return checkUtil(root, level, &leafLevel);
}