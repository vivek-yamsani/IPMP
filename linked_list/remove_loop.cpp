#include <iostream>
#include <string>
#include <vector>
using namespace std;

class node
{
public:
    int val;
    node *next;
};

// this is insertion at head
void push(node *&head, int new_data)
{

    node *new_node = new node();
    new_node->val = new_data;
    new_node->next = head;
    head = new_node;
}

void removeCycle(node *&head)
{
    node *fast = head, *slow = head;
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
        return;
    if (fast == head)
    {
        while (slow->next != head)
        {
            slow = slow->next;
        }
        slow->next = NULL;
        return;
    }
    fast = head;
    while (fast->next != slow->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = NULL;
    return;
}

int main()
{
    node *head = NULL;
    push(head, 4);
    push(head, 3);
    push(head, 2);
    push(head, 1);

    node *tmp = head;
    while (tmp->next)
    {
        tmp = tmp->next;
    }
    tmp->next = head->next;
    tmp = head;
    int i = 0;
    while (i++ < 10 && tmp)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
    removeCycle(head);
    tmp = head;
    i = 0;
    while (i++ < 10 && tmp)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    return 0;
}