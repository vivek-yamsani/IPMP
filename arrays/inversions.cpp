long long merge(long long a[], long long l, long r, long long mid)
{
    long long int n = r - l + 1, b[n], ans = 0;
    long long int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r)
    {
        if (a[i] > a[j])
        {
            ans += (mid - i + 1);
            b[k] = a[j];
            j++;
            k++;
        }
        else
        {
            b[k++] = a[i++];
        }
    }
    while (i <= mid)
    {
        b[k++] = a[i++];
    }
    while (j <= r)
    {
        b[k++] = a[j++];
    }
    k = 0;
    while (k < n)
    {
        a[l + k] = b[k];
        k++;
    }

    return ans;
}

long long int mergeSort(long long int a[], long long s, long long e)
{
    long long int inv = 0;
    if (s >= e)
        return 0;

    long long mid = (e - s) / 2 + s;

    inv += mergeSort(a, s, mid);
    inv += mergeSort(a, mid + 1, e);
    inv += merge(a, s, e, mid);

    return inv;
}

long long int inversionCount(long long a[], long long N)
{
    return mergeSort(a, 0, N - 1);
}