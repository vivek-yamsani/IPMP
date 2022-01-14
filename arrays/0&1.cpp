void segregate0and1(int arr[], int n) {
        // code here
        int zero_end = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] == 0){
                arr[i] = arr[zero_end];
                arr[zero_end++] = 0;
            }
        }
    }