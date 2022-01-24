// Complete this function
void deleteAlt(struct Node *head)
{
    // Code here
    if (head == NULL)
        return;
    struct Node *tmp = head, *del;
    while (tmp != NULL && tmp->next != NULL)
    {
        del = tmp->next;
        tmp->next = del->next;
        free(del);
        if (tmp != NULL)
            tmp = tmp->next;
    }
    return;
}