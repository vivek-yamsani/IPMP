// using sorting if always majority exists
int majorityElement(vector<int> &nums)
{
    int mid = (nums.size() - 1) / 2;

    sort(nums.begin(), nums.end());

    return nums[mid];
}

// using moores voting algorithm
int majorityElement(vector<int> &nums)
{
    int co = 0, ele = nums[0];
    for (int i : nums)
    {
        if (i == ele)
            co++;
        else
            co--;
        if (co == 0)
        {
            ele = i;
            co++;
        }
    }
    return ele;
}