/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *tmp = head, *head2 = head;
        for (int i = 0; i < n; i++)
        {
            tmp = tmp->next;
        }
        if (tmp == NULL)
        {
            tmp = head->next;
            delete head;
            return tmp;
        }
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
            head = head->next;
        }
        ListNode *del = head->next;
        head->next = head->next->next;

        delete del;
        return head2;
    }
};