int getSize(Node *node)
{
    // Your code here
    if (node == NULL)
        return 0;
    return 1 + getSize(node->right) + getSize(node->left);
}