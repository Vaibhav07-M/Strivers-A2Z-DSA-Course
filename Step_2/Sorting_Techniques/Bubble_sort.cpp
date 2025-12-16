#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[], int n) {
    for(int i=0;i<n-1;i++) {
        int swaps = 0;
        for(int j=0;j<n-i-1;j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swaps = 1;
            }
        }
        if(swaps == 0) {
            break;
        }
    }
}
int main() {
    int arr[] = {67, 89, 34, 56, 80, 13, 3, 5, 12, 45, 01, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int arr1[14] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    
    bubble_sort(arr, n);
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
    
    bubble_sort(arr1, 14);
    for(int i=0;i<14;i++) {
        cout<<arr1[i]<<" ";
    }
    
    return 0;
}