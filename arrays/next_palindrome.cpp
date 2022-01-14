#include<iostream>
#include<vector>
#include<string>
using namespace std;
// 1st case(palindrome and all 9's)
// 9999 => 10001
// 999 => 1001
// string of size+1 with both ends 1

// 2nd case(palindrome but not all 9's)
// 12921 ===> 13031
// 25352 ===> 25452
// increment mid and copy reverse of left to right 


// 3rd case(not a palindrome)
//  i) 1 4 5 8 7 6 7 8 3 2 2
//             ^   ^
//             |   |
//        <--- i   j --->
// two pointers iterate until s[i] == s[j]
// if(s[i] > s[j]) copy reverse of left to right
// else increment mid and copy reverse of left to right

string next_palindrome(int n){
    string s = to_string(n);
    bool flag = 1;
    int size = s.size();
    for(char i : s)
        if(i != '9')
        {
            flag = 0;
            break;
        }
    
    if(flag){
        string ans(size+1,'0');
        ans[0] = '1';
        ans[ans.size() - 1] = '1';
        return ans;
    }

    int mid= size/2 , i = mid -1, j = (size%2)? mid+1:mid;
    while( j < size && s[i] == s[j])
    {
        i--; j++;
    }

    if(i < 0 || s[i] < s[j])
        flag = 1;

    while(i >= 0){
        s[j++] = s[i--];
    }

//  this handles the mid incrementing thing
    if(flag){
        int carry = 1;
        i = mid - 1;

        if(n%2){
            if(s[mid] == '9'){
                s[mid] = '0';
                carry = 1;
            }
            else{
                s[mid]++;
                carry = 0;
            }
            j = mid + 1;
        }
        else
            j = mid;

        while(i >= 0){
            if(s[i] == '9' && carry == 1){
                s[i] = '0';
                carry = 1;
            }
            else if(carry == 1){
                s[i]++;
                carry = 0;
            }
            s[j++] = s[i--];
        }
    }

    return s;
}

int main(){
    int n;
    cin>>n;
    cout<<next_palindrome(n);
    return 0;
}