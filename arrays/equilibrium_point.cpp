int equilibriumPoint(long long a[], int n)
{

    // Your code here
    long long sum = 0;
    long long curr_sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    for (int i = 0; i < n; i++)
    {
        if (curr_sum == (sum - curr_sum - a[i]))
            return i + 1;

        curr_sum += a[i];
    }

    return -1;
}