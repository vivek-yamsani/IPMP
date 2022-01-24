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

void delete_list(node *&head)
{
    node *del;
    while (head)
    {
        del = head;
        head = head->next;
        delete del;
    }

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
    while (tmp)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }

    delete_list(head);
    tmp = head;
    while (tmp)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }

    return 0;
}