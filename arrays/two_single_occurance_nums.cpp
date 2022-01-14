class solution{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        int sum = 0;
        for(int i : nums) sum ^= i;
        vector<int> ans,set1,set2;
        int set_bit = sum&(~(sum-1));
        for(int i : nums)
            if(set_bit&i) set1.push_back(i);
            else set2.push_back(i);
        int temp = sum;
        for(int i : set2) temp ^= i;
        ans.push_back(temp);
        ans.push_back(temp^sum);
        
        if(ans[0]>ans[1]){
            temp = ans[0];
            ans[0] = ans[1];
            ans[1] = temp;
        }
    
        return ans;
    }
};