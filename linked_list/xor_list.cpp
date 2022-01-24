#include <iostream>
#include <string>
#include <vector>
#include <cinttypes>
using namespace std;

class node
{
public:
    int data;
    node *ptr_xor;
    node(int val)
    {
        data = val;
        ptr_xor = NULL;
    }
};

node *Xor(node *x, node *y)
{
    return reinterpret_cast<node *>(
        reinterpret_cast<uintptr_t>(x) ^ reinterpret_cast<uintptr_t>(y));
}

class xor_list
{
public:
    node *head, *tail;
    xor_list()
    {
        head = NULL;
        tail = NULL;
    }
    void insert(int data)
    {
        if (head == NULL)
        {
            head = new node(data);
            tail = head;
            return;
        }
        node *new_node = new node(data);
        new_node->ptr_xor = tail;
        tail->ptr_xor = Xor((tail->ptr_xor), new_node);
        tail = new_node;
    }

    void display()
    {
        node *tmp = head, *prev = NULL;
        while (tmp)
        {
            cout << tmp->data << " ";
            node *next = Xor(tmp->ptr_xor, prev);
            prev = tmp;
            if (next == NULL)
                break;
            tmp = next;
        }
        cout << endl;
        prev = NULL;
        while (tmp)
        {
            cout << tmp->data << " ";
            node *next = Xor(tmp->ptr_xor, prev);
            prev = tmp;
            if (next == NULL)
                break;
            tmp = next;
        }
    }
};

int main()
{
    xor_list l1;
    l1.insert(1);
    l1.insert(2);
    l1.insert(3);
    l1.insert(4);
    l1.insert(5);
    l1.display();
    return 0;
}