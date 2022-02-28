class Solution
{
public:
    void inOrder(Node *root, Node *&prev)
    {
        if (!root)
            return;
        inOrder(root->left, prev);
        if (prev)
            prev->next = root;
        prev = root;
        inOrder(root->right, prev);
    }

    void populateNext(Node *root)
    {
        Node *prev = NULL;
        inOrder(root, prev);
    }
};