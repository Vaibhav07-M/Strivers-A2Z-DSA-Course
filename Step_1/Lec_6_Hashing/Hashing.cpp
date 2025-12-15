#include <bits/stdc++.h>
using namespace std;

void number_of_occurance_basic(int arr[]) {
    int n,j;
    cout<<"No. of element you have to find ";
    cin>>n;
    while(n>0) {
        cout<<"Enter element to find ";
        cin>>j;
        int count = 0;
        for(int i=0;i<13;i++) {
            if(j == arr[i]) count++;
        }
        cout<<"found "<<j<<" ,"<<count<<" times"<<endl;
        n--;
    }
}
void number_hashing(int arr[]) {
    // Precompute
    int hash[13] ={0};
    for(int i=0;i<13;i++) {
        hash[arr[i]]++;
    }
    
    // Fetch
    int n = 0;
    cout<<"Enter the number of element u have to find ";
    cin>>n;
    while(n>0) {
        int j;
        cout<<"Enter element to find ";
        cin>>j;
        cout<<"Found "<<j<<" "<<hash[j]<<" times"<<endl;
        n--;
    }
}
void lowercase_letters(string lower) {
    // Pre compute
    int hash[26] = {0};
    for(int i=0;i<lower.size();i++) {
        hash[lower[i]-'a']++;
    }

    //Fetch
    int n;
    cout<<"Enter the number of element ";
    cin>>n;
    while(n--) {
        char j;
        cout<<"Enter the element to find ";
        cin>>j;
        cout<<"Found "<<j<<", "<<hash[j-'a']<<" times"<<endl;
    }
}
void ascii_hashing(string s) {
    // Pre compute
    int hash[256] = {0};
    for(int i=0;i<s.size();i++) {
        hash[s[i]]++;
    }
    // Fetch

    int n;
    cout<<"Enter the number of elements u have to find ";
    cin>>n;
    while(n--) {
        char j;
        cout<<"Enter the elment u have to find ";
        cin>>j;

        cout<<"Found "<<j<<", "<<hash[j]<<" times"<<endl;
    }
}
void number_hashing_using_maps(int arr[], int n) {
    // Pre compute
    unordered_map<int, int> mpp;    // if we use map<int,int> then it will be ordered map and time complexity will be O(log n) for insertion and fetching
                                     // but in unordered_map time complexity will be O(1) for insertion and fetching on average case
    for(int i=0;i<n;i++) {
        mpp[arr[i]]++;
    }

    // Fetch
    int q;
    cout<<"Enter the number of element u want to find ";
    cin>>q;
    while(q--) {
        int i;
        cout<<"Enter the number you have to find ";
        cin>>i;
        cout<<"Found "<<i<<", "<<mpp[i]<<" times"<<endl;
    }
}
bool comp(pair<int,int> a,pair<int,int> b) {
    // sorting , primarially on the basis of second element (frequency) in decending order
    // if frequency is same then on the basis of first element in ascending order
    if(a.second > b.second) return true;
    else if(a.second < b.second) return false;
    else {
        if(a.first < b.first) return true;
        else return false;
    }
}
void number_hashing_sorted(int arr[],int n) {
    unordered_map<int, int> mapp;

    for(int i=0;i<n;i++) {
        mapp[arr[i]]++;
    }
    vector<pair<int,int>> hashh(mapp.begin(),mapp.end());

    sort(hashh.begin(), hashh.end());
    for(auto it: hashh) {
        cout<<it.first<<" : "<<it.second<<endl;
    }
    cout<<endl;
    sort(hashh.begin(), hashh.end(),comp);
    for(auto it: hashh) {
        cout<<it.first<<" : "<<it.second<<endl;
    }
    cout<<endl;

    cout<<"Element with the highest frequency is "<<hashh[0].first<<" with frequency "<<hashh[0].second<<endl;
    cout<<"Element with the lowest frequency and highest value is "<<hashh[hashh.size()-1].first<<" with frequency "<<hashh[hashh.size()-1].second<<endl;
}


int main(){
    int arr[13] = {1,2,3,4,5,2,5,2,5,2,4,5,2};
    // number_of_occurance_basic(arr);
    // number_hashing(arr);
    // string lower = "abcdecbadefc";
    // lowercase_letters(lower);
    // string s = "agjv356165!@#$%^atudgq3@#$%266tys1b651yt@#";
    // ascii_hashing(s);
    int arr1[] = {1,2,3,4,5,2,1,5,7,4,2,3,6,5,3,2,5,4,2,4,6,4,2,3,5,2,5,12,12,12,12,134,35,2,24};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    // number_hashing_using_maps(arr1,n);
    number_hashing_sorted(arr1,n);


    return 0;
}