void inOrder(Node *root, int &sum)
{
    if (!root)
        return;
    inOrder(root->right, sum);
    root->data += sum;
    sum = root->data;
    inOrder(root->left, sum);
}

Node *modify(Node *root)
{
    // Your code here
    int sum = 0;
    inOrder(root, sum);
    return root;
}