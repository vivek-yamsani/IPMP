
class Solution
{
public:
    // Function to return the diameter of a Binary Tree.
    int height(Node *node)
    {
        if (node == NULL)
            return 0;
        return 1 + max(height(node->left), height(node->right));
    }
    int diameter(Node *root)
    {
        // Your code here
        if (root == NULL)
            return 0;
        int h = height(root->left) + height(root->right) + 1;
        return max(max(diameter(root->left), diameter(root->right)), h);
    }
};