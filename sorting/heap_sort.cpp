#include<iostream>
#include<vector>
using namespace std;

void max_heapify(vector<int>& arr,int index,int n){
    int largest = index;
    int left = 2*index + 1;
    int right = 2*index + 2;

    if(left < n && arr[left] > arr[largest])
        largest = left;
    if(right < n && arr[right] > arr[largest])
        largest = right;
    if(largest != index){
        int temp = arr[largest];
        arr[largest] = arr[index];
        arr[index] = temp;
    
        max_heapify(arr,largest,n);
    }

}

void build_heap(vector<int>& arr,int n){
    for(int i = (n/2)-1; i >= 0;i--){
        max_heapify(arr,i,n);
    }
}

void heap_sort(vector<int>& arr,int n){
    build_heap(arr,n);

    for(int i = n-1; i > 0;i--){
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        max_heapify(arr,0,i);
    }
}

int main(){
    vector<int> v = {1,4,5,2,3};
    for(int i : v){
        cout<< i << " ";
    }
    cout<<endl;
    heap_sort(v,5);
    for(int i : v){
        cout<< i << " ";
    }
    cout<<endl;
}