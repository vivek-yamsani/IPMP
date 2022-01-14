class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0,it = 0, two = nums.size() - 1;
        while(it <= two){
            if(nums[it] == 0){
                nums[it] = nums[zero];
                nums[zero] = 0;
                it++;zero++;
            }
            else if(nums[it] == 1){
                it++;              
            }
            else{
                nums[it] = nums[two];
                nums[two] = 2;
                two--;
            }
        }
    }
};