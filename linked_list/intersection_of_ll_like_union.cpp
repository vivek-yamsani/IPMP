Node *findIntersection(Node *head1, Node *head2)
{
    // Your Code Here
    if (head1 == NULL || head2 == NULL)
        return NULL;
    Node *ptr1 = head1, *ptr2 = head2;
    Node *new_head = NULL, *tail = new_head;
    while (ptr1 && ptr2)
    {
        if (ptr1->data == ptr2->data)
        {
            if (tail == NULL)
            {
                new_head = new Node(ptr1->data);
                tail = new_head;
            }
            else
            {
                tail->next = new Node(ptr1->data);
                tail = tail->next;
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if (ptr1->data > ptr2->data)
        {
            ptr2 = ptr2->next;
        }
        else
        {
            ptr1 = ptr1->next;
        }
    }

    return new_head;
}