#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high) {
    int pivotIndex = low + rand() % (high - low + 1);
    swap(arr[pivotIndex], arr[high]);
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
void quick_sort(vector<int> &arr, int low, int high) {
    while(low<high) {
        int p = partition(arr, low, high);
        if(p-low < high - p) {
            quick_sort(arr, low, p-1);
            low = p + 1;
        } else {
            quick_sort(arr, p+1, high);
            high = p - 1;
        }
    }    
    return;
}

int main() {
    srand(time(0));
    vector<int> arr = {56,23,45,78,23,12,4,5,67,78,89,87,34,2,312,34,4,7};
    
    cout<<"Before: ";
    for(int x : arr) cout<<x<<" ";

    quick_sort(arr, 0, arr.size() - 1);

    cout<<"\nAfter: ";
    for(int x : arr) cout<<x<<" ";

    return 0;
}