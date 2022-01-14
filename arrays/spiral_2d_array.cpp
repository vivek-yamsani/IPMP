class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int c = matrix[0].size(),r = matrix.size();
        int size = (r)*(c);
        
        vector<int> arr(size);
        int i = 0,r_st = 0,r_end = r-1,c_st = 0,c_end = c-1;
        while(i < r*c){
            int rit = r_st,cit = c_st;
            while(cit <= c_end){
               arr[i++] = matrix[r_st][cit++];
            }
            r_st++;
            rit = r_st;
            if(r_st > r_end) break;
            while(rit <= r_end){
                arr[i++] = matrix[rit++][c_end];
            }
            c_end--;
            cit = c_end;
            while(cit >= c_st){
                arr[i++] = matrix[r_end][cit--];
            }
            r_end--;
            rit = r_end;
            if(c_st > c_end) break;
            while(rit >= r_st){
                arr[i++] = matrix[rit--][c_st];
            }
            c_st++;
        }
        return arr;
    }
};