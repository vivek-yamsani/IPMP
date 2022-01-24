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
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *dummy = new ListNode(0, head), *ptr = head, *left = dummy, *right;
        while (ptr && ptr->next)
        {
            right = ptr->next->next;
            ptr->next->next = ptr;
            left->next = ptr->next;
            ptr->next = right;

            left = ptr;
            ptr = ptr->next;
        }

        return dummy->next;
    }
};