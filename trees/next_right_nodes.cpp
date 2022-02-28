// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root)
            return NULL;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                Node *curr = q.front();
                q.pop();
                Node *next;
                if (i != size - 1)
                    next = q.front();
                else
                    next = NULL;
                curr->next = next;

                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
        }
        return root;
    }
};