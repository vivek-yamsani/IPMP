void doubleTree(node *Node)
{
    node *oldLeft;

    if (Node == NULL)
        return;

    doubleTree(Node->left);
    doubleTree(Node->right);

    oldLeft = Node->left;
    Node->left = newNode(Node->data);
    Node->left->left = oldLeft;
}