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
    ListNode *swapNodes(ListNode *head, int k)
    {
        int t, count = 0;
        ListNode *tmp1 = head, *tmp2 = head, *tmp;
        while (count < k - 1)
        {
            tmp1 = tmp1->next;
            count++;
        }
        tmp = tmp1;

        while (tmp1->next)
        {
            tmp2 = tmp2->next;
            tmp1 = tmp1->next;
        }
        t = tmp2->val;
        tmp2->val = tmp->val;
        tmp->val = t;

        return head;
    }
};