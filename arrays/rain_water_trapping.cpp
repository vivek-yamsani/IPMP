class Solution {
public:
    int trap(vector<int>& height) {
        int max = 0,n = height.size();
        vector<int> l1(n),l2(n);
        for(int i = 0; i < n; i++){
            l1[i] = max;
            max = max > height[i] ? max : height[i];
        }
        max = 0;
        for(int i = n - 1 ; i >= 0; i--){
            l2[i] = max;
            max = max > height[i] ? max : height[i];
        }
        
        int ans = 0;
        for(int i = 0; i < n;i++){
            int hi = min(l1[i],l2[i]);
            if(hi > height[i]){
                ans += (hi - height[i]);
            }
        }
        
        return ans;
    }
};