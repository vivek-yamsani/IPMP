class Solution
{
public:
    // Function to return a list containing the inorder traversal of the tree.
    void util(Node *root, vector<int> &ans)
    {
        if (!root)
            return;
        util(root->left, ans);
        ans.push_back(root->data);
        util(root->right, ans);
    }
    vector<int> inOrder(Node *root)
    {
        // Your code here
        vector<int> ans;
        util(root, ans);

        return ans;
    }
};

void util(Node *root, vector<int> &ans)
{
    if (!root)
        return;
    ans.push_back(root->data);
    util(root->left, ans);
    util(root->right, ans);
}
vector<int> preorder(Node *root)
{
    // Your code here
    vector<int> ans;
    util(root, ans);

    return ans;
}

void util(Node *root, vector<int> &ans)
{
    if (!root)
        return;
    util(root->left, ans);
    util(root->right, ans);
    ans.push_back(root->data);
}
vector<int> postOrder(Node *root)
{
    // Your code here
    vector<int> ans;
    util(root, ans);

    return ans;
}