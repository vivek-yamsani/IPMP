int minValue(struct Node *root)
{
    // your code here

    if (!root)
        return -1;

    if (root->left == NULL)
        return root->data;

    return minValue(root->left);
}