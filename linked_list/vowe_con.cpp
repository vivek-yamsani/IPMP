bool isVowel(char a)
{
    if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
        return true;
    return false;
}

struct Node *arrange(Node *head)
{
    // Code here
    struct Node *vo = new Node(1), *vowel = vo, *con = new Node(1), *con_last = con;
    struct Node *ptr = head;
    while (ptr)
    {
        if (isVowel(ptr->data))
        {
            vowel->next = ptr;
            vowel = vowel->next;
        }
        else
        {
            con_last->next = ptr;
            con_last = con_last->next;
        }
        ptr = ptr->next;
    }

    con_last->next = NULL;
    vowel->next = con->next;

    return vo->next;
}