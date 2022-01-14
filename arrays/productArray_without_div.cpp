vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
    //code here        
    vector<long long int> ans(n);
    ans[0] = 1;
    for(int i = 1; i < n; i++){
        ans[i] = ans[i-1] * nums[i-1];
    }
    long long int tmp = 1;
    for(int i = n-1; i >= 0;i--){
        ans[i] = ans[i]*tmp;
        tmp = tmp*nums[i];
    }

    return ans;
}