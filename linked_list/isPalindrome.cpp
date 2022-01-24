class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *fast = head, *slow = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        if (fast)
            slow = slow->next;
        ListNode *prev = NULL, *next;
        while (slow)
        {
            next = slow->next;

            slow->next = prev;
            prev = slow;
            slow = next;
        }
        fast = head;
        while (prev)
        {
            if (prev->val != fast->val)
                return false;
            prev = prev->next;
            fast = fast->next;
        }

        return true;
    }
};