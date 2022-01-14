void segregateEvenOdd(int a[], int n) {
	    // code here
	    int eve_end = 0;
	    for(int i = 0; i < n; i++){
	        if(a[i]%2 == 0){
	            if(i != eve_end)
	            {
	                int temp = a[eve_end];
	                a[eve_end] = a[i];
	                a[i] = temp;
	            }
	            eve_end++;
	        }
	    }
	    sort(a,a+eve_end);
	    sort(a+eve_end,a+n);
	}

