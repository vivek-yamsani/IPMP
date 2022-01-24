/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *fast = head, *slow = head;
        bool flag = 0;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
            {
                flag = 1;
                break;
            }
        }
        // flag is necessary because fast != slow is not satisfied for only single node list
        if (!flag)
            return NULL;
        fast = head;
        while (fast != slow)
        {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};