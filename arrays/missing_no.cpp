class Solution{
  public:
    int MissingNumber(vector<int>& arr, int n) {
        int sum = 0,tot = (n*(n+1))/2;
        for(int i:arr) sum += i;
        return tot-sum;
    }
};