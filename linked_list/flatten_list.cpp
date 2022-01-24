Node *merge(Node *l1, Node *l2)
{
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    Node *new_head = new Node(0), *ptr1 = l1, *ptr2 = l2, *end = new_head;
    while (ptr1 && ptr2)
    {
        if (ptr1->data < ptr2->data)
        {
            end->bottom = ptr1;
            ptr1 = ptr1->bottom;
        }
        else
        {
            end->bottom = ptr2;
            ptr2 = ptr2->bottom;
        }
        end = end->bottom;
    }
    if (ptr1 == NULL && ptr2 != NULL)
        end->bottom = ptr2;
    else if (ptr2 == NULL && ptr1 != NULL)
        end->bottom = ptr1;

    return new_head->bottom;
}

Node *flatten(Node *root)
{
    // Your code here
    Node *new_head = NULL, *tmp = root;
    while (tmp)
    {
        new_head = merge(new_head, tmp);
        tmp = tmp->next;
    }
    tmp = new_head;
    while (tmp)
    {
        tmp->next = tmp->bottom;
        tmp = tmp->next;
    }

    return new_head;
}