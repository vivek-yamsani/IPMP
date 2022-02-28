
// optimisied
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == p || root == q || root == NULL)
        return root;
    TreeNode *parent1 = dfsTraverse(root->left, p, q);
    TreeNode *parent2 = dfsTraverse(root->right, p, q);
    if (parent1 && parent2)
        return root;
    else
        return parent1 ? parent1 : parent2;
}

class Solution
{
public:
    void there(TreeNode *root, TreeNode *p, TreeNode *q, bool &p_th, bool &q_th)
    {
        if (!root)
            return;
        if (root == p)
            p_th = 1;
        if (root == q)
            q_th = 1;

        there(root->left, p, q, p_th, q_th);
        there(root->right, p, q, p_th, q_th);
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        bool p_th = 0, q_th = 0;
        there(root->left, p, q, p_th, q_th);
        if (p_th && q_th)
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        p_th = 0, q_th = 0;
        there(root->right, p, q, p_th, q_th);
        if (p_th && q_th)
        {
            return lowestCommonAncestor(root->right, p, q);
        }

        return root;
    }
};