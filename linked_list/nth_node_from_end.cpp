int getNthFromLast(Node *head, int n)
{
    // Your code here

    Node *main = head, *temp = head;
    for (int i = 1; i < n; i++)
    {
        if (temp == NULL)
            return -1;
        temp = temp->next;
    }
    if (temp == NULL)
        return -1;
    while (temp->next != NULL)
    {
        temp = temp->next;
        main = main->next;
    }
    return main->data;
}
