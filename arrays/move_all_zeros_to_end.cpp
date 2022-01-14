class Solution{
public:
	void pushZerosToEnd(int arr[], int n) {
	    // code here
	    int i = 0,it = 0;
	    while(it < n){
	        if(arr[it] != 0){
	            arr[i++] = arr[it];
	        }
	        it++;
	    }
	    while(i < n){
	        arr[i++] = 0;
	    }
	}
};