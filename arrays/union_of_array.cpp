// Union and Intersection of two sorted arrays
class Solution
{
public:
    // Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)
    {
        int c[n + m];
        int i = 0, j = 0, k = 0;
        sort(a, a + n);
        sort(b, b + m);
        while (i < n && j < m)
        {
            if (a[i] < b[j])
            {
                if ((k > 0 && c[k - 1] != a[i]) || k == 0)
                    c[k++] = a[i++];
                else
                    i++;
            }
            else
            {
                if ((k > 0 && c[k - 1] != b[j]) || k == 0)
                    c[k++] = b[j++];
                else
                    j++;
            }
        }
        while (i < n)
        {
            if ((k > 0 && c[k - 1] != a[i]) || k == 0)
                c[k++] = a[i++];
            else
                i++;
        }
        while (j < m)
        {
            if ((k > 0 && c[k - 1] != b[j]) || k == 0)
                c[k++] = b[j++];
            else
                j++;
        }
        return k;
    }
};