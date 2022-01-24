Node *copyList(Node *head)
{
    // Write your code here
    Node *tmp = head, *new_head = new Node(0), *end = new_head;
    unordered_map<Node *, Node *> mp;
    while (tmp)
    {
        end->next = new Node(tmp->data);
        end = end->next;
        mp[tmp] = end;
        tmp = tmp->next;
    }
    end->next = NULL;
    end = new_head->next;
    tmp = head;
    while (tmp)
    {
        end->arb = mp[tmp->arb];
        end = end->next;
        tmp = tmp->next;
    }

    return new_head->next;
}

// LeetCode Question

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        Node *tmp = head, *new_head = new Node(0), *end = new_head;
        unordered_map<Node *, Node *> mp;
        while (tmp)
        {
            end->next = new Node(tmp->val);
            end = end->next;
            mp[tmp] = end;
            tmp = tmp->next;
        }
        end->next = NULL;
        end = new_head->next;
        tmp = head;
        while (tmp)
        {
            end->random = mp[tmp->random];
            end = end->next;
            tmp = tmp->next;
        }

        return new_head->next;
    }
};