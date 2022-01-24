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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2, int c = 0)
    {
        if (l1 == NULL && l2 == NULL)
        {
            if (c == 0)
                return NULL;
            else
            {
                ListNode *n = new ListNode(c % 10);
                c = c / 10;
                n->next = addTwoNumbers(l1, l2, c);

                return n;
            }
        }
        if (l1 == NULL)
        {
            l2->val = l2->val + c;
            c = (l2->val) / 10;
            l2->val = (l2->val) % 10;
            l2->next = addTwoNumbers(l1, l2->next, c);
            return l2;
        }
        if (l2 == NULL)
        {
            l1->val = l1->val + c;
            c = (l1->val) / 10;
            l1->val = (l1->val) % 10;
            l1->next = addTwoNumbers(l1->next, l2, c);
            return l1;
        }

        ListNode *n = new ListNode();
        n->val = l1->val + l2->val + c;
        c = (n->val) / 10;
        n->val = (n->val) % 10;

        n->next = addTwoNumbers(l1->next, l2->next, c);

        return n;
    }
};