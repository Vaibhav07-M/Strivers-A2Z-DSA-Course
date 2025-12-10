#include <bits/stdc++.h>
using namespace std;

void print_n_asc(int i, int n) {
    if(i>n) return;
    cout<<i<<" ";
    print_n_asc(i+1,n);
}
void print_n_dec(int i, int n) {
    if(n<1) return;
    cout<<n<<" ";
    print_n_dec(i,n-1);
}
void print_sum(int i, int n, int sum = 0) {
    if(i>n){
        cout<<sum;
        return;
    }
    print_sum(i+1,n,sum+i);
}
void print_factorial(int n, int sum = 1) {
    if(n<1) {
        cout<<sum;
        return;
    }
    print_factorial(n-1,sum*n);
}
void print_array(int arr[], int n, int i = 0) {
    cout<<arr[i]<<" ";
    if(i==n) return;
    print_array(arr, n, i+1);
}
void print_reverse_array(int arr[], int n) {
    cout<<arr[n]<<" ";
    if(n==0) return;
    print_reverse_array(arr, n-1);
}
bool print_palindrome(string& s, int i) {
    if(i > s.length()/2) return true;
    if(s[i] != s[s.length() -i - 1]) return false;
    return print_palindrome(s,i+1);
}
int faboncci(int n) {
    if(n==0) return n;
    if(n==1) return n;
    return faboncci(n-1) + faboncci(n-2);
}

int main() {
    print_n_asc(1, 5);
    cout<<endl;
    print_n_dec(1, 5);
    cout<<endl;
    print_sum(1,5);
    cout<<endl;
    print_factorial(5);
    cout<<endl;
    int arr[] = {1,2,3,4};
    print_array(arr, 3);
    cout<<endl;
    print_reverse_array(arr, 3);
    cout<<endl;
    string s = "racecar";
    print_palindrome(s,0) ? cout<<"true" : cout<<"false";
    cout<<endl;
    cout<<faboncci(6);
    return 0;
}