class Solution
{
public:
    int binary(int key, int st, int end, vector<int> &n)
    {
        if (st > end)
            return -1;

        int mid = (end - st) / 2 + st;

        if (n[mid] == key)
            return mid;
        if (n[mid] > key)
            return binary(key, st, mid - 1, n);
        else
            return binary(key, mid + 1, end, n);
    }
    int search(vector<int> &n, int target, int st = 0, long long int end = (long long int)1e10)
    {
        if (end == (long long int)1e10)
            end = n.size() - 1;
        if (st > end)
            return -1;
        int mid = (end - st) / 2 + st;
        if (n[mid] == target)
            return mid;
        if (n[mid] >= n[st])
        {
            if (target < n[mid] && target >= n[st])
            {
                return binary(target, st, mid - 1, n);
            }
            else
                return search(n, target, mid + 1, end);
        }
        else
        {
            if (target > n[mid] && target <= n[end])
                return binary(target, st, end, n);
            else
                return search(n, target, st, mid - 1);
        }
    }
};