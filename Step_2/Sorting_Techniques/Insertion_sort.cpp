#include <bits/stdc++.h>
using namespace std;

void Insertion_sort(int arr[], int n) {
    for(int i=1;i<n;i++) {
        int min = i;
        int key = arr[i];
        while(min>0 && key<arr[min-1]) {
            arr[min] = arr[min-1];
            min--;
        }
        arr[min] = key;
    }
}

int main() {
    int arr[] = {78,45,12,67,89,2,12,35,57,23,1,57,78,23,23,34,98};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    Insertion_sort(arr, n);
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }

    return 0;
}