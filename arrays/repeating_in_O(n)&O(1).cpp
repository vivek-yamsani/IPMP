class Solution{
public:	
	// Returns maximum repeating element in arr[0..n-1].
	// The array elements are in range from 0 to k-1
	int maxRepeating(int *arr, int n, int k) {
	    // code here
	    for(int i = 0; i < n; i++){
	        arr[arr[i]%n] += n;
	    }
	    int mx = 0,in = 0;
	    for(int i = 0; i< k;i++){
	        if(mx < arr[i]/n){
	            mx = arr[i]/n;
	            in = i;
	        }
	    }
	    
	    return in;
	}

};