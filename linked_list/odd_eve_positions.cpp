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
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *odd = head, *eve = head->next, *eve_last = eve, *ptr = odd->next->next;
        while (ptr)
        {
            odd->next = ptr;
            eve_last->next = ptr->next;
            odd = odd->next;
            eve_last = eve_last->next;

            if (ptr->next)
                ptr = ptr->next->next;
            else
                break;
        }
        odd->next = eve;
        if (eve_last)
            eve_last->next = NULL;

        return head;
    }
};