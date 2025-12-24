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
void arr_union(vector<int> &arr1,vector<int> &arr2) {
    int i = 0;
    int j = 0;
    vector<int> temp;
    int m = arr1.size();
    int n = arr2.size();
    // vector<int> arr5 = {1,3,4,6,7,8,9};
    // vector<int> arr6 = {1,2,3,4,6,7,8};

    while(i<m && j<n) {
        if(arr1[i] == arr2[j]){
            if(temp.empty() || temp.back() != arr1[i]){
                temp.push_back(arr1[i]);
            }
            i++;
            j++;
        }
        else if(arr1[i]<arr2[j]) {
            if(temp.empty() || temp.back() != arr1[i]){
                temp.push_back(arr1[i]);
            }
            i++;
        }
        else if(arr1[i]>arr2[j]) {
            if(temp.empty() || temp.back() != arr2[j]){
                temp.push_back(arr2[j]);
            }
            j++;
        }
    }
    while(i<m) {
        if(temp.empty() || temp.back() != arr1[i]){
            temp.push_back(arr1[i]);
        }
        i++;
    }
    while(j<n) {
        if(temp.empty() || temp.back() != arr2[j]){
            temp.push_back(arr2[j]);
        }
        j++;
    }
    cout<<"\nUnion of "<<endl;
    for(int i=0;i<m;i++) {
        cout<<arr1[i]<<" ";
    }
    cout<<"and "<<endl;
    for(int i=0;i<n;i++) {
        cout<<arr2[i]<<" ";
    }
    cout<<"is "<<endl;
    for(int i=0;i<temp.size();i++) {
        cout<<temp[i]<<" ";
    }
}
void missing_number(vector<int> &arr) {
    int n = arr.size();
    int result = (n*(n+1))/2;
    int sum = 0;
    for(int i=0;i<n;i++) {
        sum+=arr[i];
    }
    cout<<"\nMissing number from array: "<<result-sum<<endl;
}
void maxconsecutive_ones(vector<int> &arr) {
    int max_count = 0;
    int count = 0;
    for(int i=0;i<arr.size();i++) {
        if(arr[i]==1) {
            count++;
        }
        else {
            if(count>=max_count || max_count==0) {
                max_count = count;
                count = 0;
            }
            else {
                count = 0;
            }
        }
    }
    if(count>max_count) {
        max_count = count;
    }
    cout<<"Maximum consecutive ones: "<<max_count<<endl;
    // or 
    // int max_count = 0, count = 0;
    // for(int x : arr) {
    //     if(x == 1) {
    //         count++;
    //         max_count = max(max_count,count);
    //     }
    //     else {
    //         count = 0;
    //     }
    // }
    // cout<<"\nMaximum consecutive ones: "<<max_count<<endl;
}
void one_occurence(vector<int> &arr) {
    int n = arr.size();
    int xorr = 0;
    for(int i=0;i<n;i++) {
        xorr = xorr ^ arr[i];
    }
    cout<<"Element with one occurence: "<<xorr<<endl;
    
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
    
    vector<int> arr5 = {1,3,4,6,7,8,9};
    vector<int> arr6 = {1,2,3,4,6,7,8};
    arr_union(arr5,arr6);

    vector<int> arr7 = {9,1,3,4,5,6,7,8,2};
    missing_number(arr7);
    vector<int> arr8 = {1,1,1,0,1,1,1,1,1,0,1,1,1};
    maxconsecutive_ones(arr8);

    vector<int> arr9 = {2,3,5,4,5,3,2,4,6,7,6};
    one_occurence(arr9);
}