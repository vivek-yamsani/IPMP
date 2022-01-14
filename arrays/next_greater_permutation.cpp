#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

string next_greater_permutation(int n){
    string s = to_string(n);
    int size = s.size(),i;
    for(i = size -2 ; i >= 0 ;i--){
        if(s[i] < s[i+1]) break;
    }
    if(i < 0) return "-1";

    char mn = '9';int mn_idx = i;
    for(int j = i; j < size;j++){
        if(s[j] > s[i] && s[j] < mn){
            mn = s[j];
            mn_idx = j;
        }
    }

    s[mn_idx] = s[i];
    s[i] = mn;

    sort(s.begin()+i+1,s.end());

    return s;
}

int main(){
    int n;
    cin>>n;
    cout<<next_greater_permutation(n);
    return 0;
}