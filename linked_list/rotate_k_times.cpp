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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL)
            return NULL;
        ListNode *fast = head, *slow = head, *new_head;
        int len = 0;
        while (fast)
        {
            len++;
            fast = fast->next;
        }
        k = k % len;
        if (k == 0)
            return head;
        fast = head;
        while (k--)
            fast = fast->next;
        while (fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = head;
        new_head = slow->next;
        slow->next = NULL;

        return new_head;
    }
};

// for k <= len and small k
Node *rotate(Node *head, int k)
{
    // Your code here
    if (head == NULL || k == 0)
        return head;
    Node *fast = head, *slow = head;
    while (fast->next != NULL)
    {
        fast = fast->next;
    }
    for (int i = 1; i <= k; i++)
    {
        fast->next = head;
        head = head->next;
        fast = fast->next;
    }

    fast->next = NULL;

    return head;
}