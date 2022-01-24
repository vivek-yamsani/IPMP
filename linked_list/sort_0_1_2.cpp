class Solution
{
public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node *segregate(Node *head)
    {

        // Add code here
        int count[3] = {0, 0, 0};
        Node *tmp = head;
        while (tmp)
        {
            count[tmp->data]++;
            tmp = tmp->next;
        }
        int i = 0;
        tmp = head;
        while (tmp)
        {
            while (count[i] == 0)
                i++;
            tmp->data = i;
            count[i]--;
            tmp = tmp->next;
        }

        return head;
    }
};