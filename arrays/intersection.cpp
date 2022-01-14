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

        // idea is that larger element can be present in reaining array
        
        while (i < n && j < m)
        {
            if (a[i] < b[j])
            {
                i++;
            }
            else if(a[i] > b[j])
            {
                j++;
            }
            else{
                c[k++] = a[i++];
                j++;
            }
        }
        
        return k;
    }
};