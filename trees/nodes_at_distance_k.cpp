void Util(Node *root, int level, vector<int> &ans)
{
    if (!root)
        return;
    if (level == 0)
    {
        ans.push_back(root->data);
        return;
    }

    Util(root->left, level - 1, ans);
    Util(root->right, level - 1, ans);
}

vector<int> Kdistance(struct Node *root, int k)
{
    // Your code here

    vector<int> ans;
    Util(root, k, ans);

    return ans;
}