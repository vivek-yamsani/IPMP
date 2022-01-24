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
    ListNode *reverse(ListNode *head, ListNode *tail)
    {
        if (head == NULL)
            return NULL;
        ListNode *prev = tail, *curr = head, *next;
        while (curr != tail)
        {
            next = curr->next;

            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *tmp = head;
        int co = k;
        while (tmp && --co)
        {
            tmp = tmp->next;
        }
        if (co == 0 && tmp)
        {
            ListNode *next = reverseKGroup(tmp->next, k);
            tmp->next = next;
            ListNode *new_head = reverse(head, next);

            return new_head;
        }

        return head;
    }
};