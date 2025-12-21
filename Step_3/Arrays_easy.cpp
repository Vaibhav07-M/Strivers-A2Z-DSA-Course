#include <bits/stdc++.h>
using namespace std;

void largest_number(vector<int> arr, int n) {
    if(n==0) {
        cout<<"Array is empty"<<endl;
        return;
    }
    int largest = arr[0];
    for(int i=0;i<n;i++) {
        if(largest<arr[i]) largest = arr[i];
    }
    cout<<"Largest element: "<<largest<<endl;
} 
void second_largest_number(vector<int> arr, int n) {
    if(n==0) {
        cout<<"Array is empty"<<endl;
        return;
    }
    if(n==1) {
        cout<<"Array has only one element"<<endl;
        return;
    }
    int largest = arr[0];
    int second_largest = INT_MIN;
    for(int i=0;i<n;i++) {
        if(largest<arr[i]) {
            second_largest = largest;
            largest = arr[i];
        }
        else if(second_largest<arr[i] && largest!=arr[i]) second_largest = arr[i];
    }
    cout<<"Second largest element: "<<second_largest<<endl;
} 
void check_sorted(vector<int> arr, int n) {
    for(int i=1;i<n;i++) {      //Check for ascedning sorting
        if (arr[i]<arr[i-1]) {
            cout<<"Not sorted";
            return;
        }
    }
    cout<<"sorted";
}
void remove_dublicate_sorted_array(vector<int> arr, int n) {
    if(arr.empty()) {
        cout<<"Array is empty";
        return;
    }
    int i = 0;
    for(int j=1;j<arr.size();j++) {
        if(arr[j]!=arr[i]) {
            i++;
            arr[i] = arr[j];
        }
    }
    cout<<"Array after removing dublicates: ";
    for(int k=0;k<=i;k++) {
        cout<<arr[k]<<" ";
    }
}
void left_shift(vector<int> arr,int n) {
    if(n==0) {
        cout<<"array is empty";
    }
    int temp = arr[0];
    for(int i=1;i<n;i++) {
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;

    cout<<"\nArray after left shift: ";
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
}
void left_shift_by_k(vector<int> arr,int k) {
    if(arr.empty()) {
        cout<<"array is empty";
    }
    int n = arr.size();
    k = k%n; //in case k>n

    reverse(arr.begin(),arr.begin()+k);
    reverse(arr.begin()+k,arr.end());
    reverse(arr.begin(),arr.end());

    cout<<"\nArray after left shift by k: ";
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
}
void move_zeros(vector<int> arr) {
    int j = -1;
    for(int i=0;i<arr.size();i++) {
        if(arr[i] == 0) {
            j=i;
            break;
        }
    }
    if(j==-1) {
        cout<<"\nnon zero array";
    }
    for(int i=j+1;i<arr.size();i++) {
        if(arr[i]!=0) {
            swap(arr[i],arr[j]);
            j++;
        }
    }
    cout<<"\nNon zero arr first: ";
    for(int i=0;i<arr.size();i++) {
        cout<<arr[i]<<" ";
    }
}

int main() {
    vector<int> arr = {2,5,9,7,3,2,6,7,9,0,2,4};
    
    largest_number(arr,arr.size());
    
    second_largest_number(arr,arr.size());
    
    vector<int> arr2 = {1,2,3,4,5,6};
    check_sorted(arr2,arr2.size());
    
    vector<int> arr3 = {1,2,2,2,2,2,2,3,4,5,5,5,6,6,6,6};
    remove_dublicate_sorted_array(arr3,arr3.size());
    
    left_shift(arr2,arr2.size());
    
    left_shift_by_k(arr2,2);

    vector<int> arr4 = {1,3,0,6,0,4,9,0,0,6,3,0};
    move_zeros(arr4);
}