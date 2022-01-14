
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k%n;
    if(k == 0) return;
    vector<int> a;
    for(int i = n-k; i<n;i++) a.push_back(nums[i]);
    for(int i = n-1;i>=k;i--) nums[i] = nums[i-k];
    for(int i = 0;i<k;i++) nums[i] = a[i];
}


void rotate(vector<int>& nums, int k) {
    int n =nums.size();
    reverse(nums.begin() , nums.begin()+(n-(k)%n));
    reverse(nums.begin()+(n-(k)%n),nums.end());
    reverse(nums.begin(),nums.end());
}