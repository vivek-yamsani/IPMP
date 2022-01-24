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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;
        ListNode *new_head = NULL, *tail = new_head;
        ListNode *ptr1 = list1, *ptr2 = list2;
        while (ptr1 && ptr2)
        {
            if (ptr1->val > ptr2->val)
            {
                if (new_head == NULL)
                {
                    new_head = ptr2;
                    tail = ptr2;
                }
                else
                {
                    tail->next = ptr2;
                    tail = tail->next;
                }
                ptr2 = ptr2->next;
            }
            else
            {
                if (new_head == NULL)
                {
                    new_head = ptr1;
                    tail = ptr1;
                }
                else
                {
                    tail->next = ptr1;
                    tail = tail->next;
                }
                ptr1 = ptr1->next;
            }
        }
        if (ptr1 == NULL && ptr2 != NULL)
            tail->next = ptr2;
        else if (ptr1 != NULL && ptr2 == NULL)
            tail->next = ptr1;

        return new_head;
    }

    ListNode *sortList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *mid = head, *fast = head, *prev;
        while (fast && fast->next)
        {
            prev = mid;
            mid = mid->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        ListNode *fir = sortList(head);
        ListNode *sec = sortList(mid);
        ListNode *new_head = mergeTwoLists(fir, sec);

        return new_head;
    }
};