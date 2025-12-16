#include <bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int n) {
    for(int i=0;i<n-1;i++) {
        int min = i;
        for(int j=i;j<n;j++) {
            if(arr[min]>arr[j]) min = j;
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int arr[] = {12, 3, 34, 45, 76, 78, 90, 0, 13, 46, 35};
    int n = sizeof(arr)/sizeof(arr[0]);

    selection_sort(arr,n);

    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }

    return 0;
}