bool straight = 0;
vector<int> findSpiral(Node *root)
{
    // Your code here
    vector<int> ans;
    if (!root)
        return ans;
    deque<Node *> q;
    q.push_back(root);
    bool straight = 0;
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *tmp;
            if (straight)
            {
                tmp = q.front();
                q.pop_front();
                if (tmp->left)
                    q.push_back(tmp->left);
                if (tmp->right)
                    q.push_back(tmp->right);
            }
            else
            {
                tmp = q.back();
                q.pop_back();
                if (tmp->right)
                    q.push_front(tmp->right);
                if (tmp->left)
                    q.push_front(tmp->left);
            }
            ans.push_back(tmp->data);
        }
        straight = !straight;
    }

    return ans;
}