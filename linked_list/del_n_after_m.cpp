class Solution
{
public:
    void linkdelete(struct Node *head, int M, int N)
    {
        // Add code here
        Node *tmp = head;
        while (tmp)
        {
            int count = 0;
            Node *tmp2 = NULL;
            while ((count < M - 1) && tmp)
            {
                tmp = tmp->next;
                count++;
            }
            if (tmp)
                tmp2 = tmp->next;
            else
                break;
            count = 0;
            while ((count < N) && tmp2)
            {
                tmp2 = tmp2->next;
                count++;
            }
            tmp->next = tmp2;
            tmp = tmp->next;
        }
    }
};