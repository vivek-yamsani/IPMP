class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        // Code here
        vector<int> ans;stack<int> s;
        int mx = INT_MIN;
        for(int i = n-1; i >= 0;i--){
            if(a[i] >= mx){
                s.push(a[i]);
                mx = a[i];
            }
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        
        return ans;
    }
};