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

void print_reverse(node *head)
{
    if (head->next == NULL)
    {
        cout << head->val << " ";
        return;
    }
    print_reverse(head->next);
    cout << head->val << " ";
}

int main()
{
    node *head = NULL;
    push(head, 4);
    push(head, 3);
    push(head, 2);
    push(head, 1);

    print_reverse(head);
    return 0;
}