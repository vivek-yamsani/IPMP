#include <iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(auto &i : a) cin>>i;
        sort(a.begin(),a.end());
        int count = 1;
        map<int,vector<int>> m;
        for(int i = 0 ; i < n - 1; i++){
            if(a[i] != a[i+1]){
                m[count].push_back(a[i]);
                count = 1;
            }
            else
                count++;
        }
        m[count].push_back(a[n-1]);
        
        int iter = n-1;
        for(auto i : m){
            for(int j = i.second.size()-1; j >=0 ;j--){
                int co = i.first;
                while(co--) a[iter--] = i.second[j];
            }
        }
        
        for(int i : a) cout<<i <<" ";
        cout<<"\n";
    }
	return 0;
}