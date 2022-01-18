void stockBuySell(int price[], int n) {
    // code here
    int  i = 1, ans = 0;
    while(i < n){
        int buy;
        while(i < n && price[i] <= price[i - 1])
            i++;
        buy = i - 1;
        if(i >= n-1)
            return;
        while(i < n && price[i] > price[i - 1])
            i++;
        cout<<"("<<buy<<" "<<i - 1<<") ";
        ans = 1;
    }
    if(ans == 0)
        cout<<"No Profit";
    cout<<"\n";
}