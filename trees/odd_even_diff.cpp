
class Solution
{
public:
    /*You are required to complete this function*/
    int getLevelDiff(Node *root)
    {
        // Your code here
        int odd = 0, even = 0;
        if (!root)
            return 0;

        queue<Node *> q;
        q.push(root);
        bool o = 1;
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                Node *tmp = q.front();
                q.pop();
                if (tmp->left)
                    q.push(tmp->left);
                if (tmp->right)
                    q.push(tmp->right);

                if (o)
                    odd += tmp->data;
                else
                    even += tmp->data;
            }
            o = !o;
        }

        return odd - even;
    }
};
