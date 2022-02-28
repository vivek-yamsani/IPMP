class Solution
{
public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')

    void Util(Node *root, Node *x, Node *&prev, Node *&ans)
    {
        if (!root)
            return;

        Util(root->left, x, prev, ans);
        if (prev == x)
        {
            ans = root;
            return;
        }
        prev = root;
        Util(root->right, x, prev, ans);
    }

    Node *inOrderSuccessor(Node *root, Node *x)
    {
        // Your code here
        Node *prev = NULL, *ans = NULL;
        Util(root, x, prev, ans);

        return ans;
    }
};