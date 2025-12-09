#include <bits/stdc++.h>
using namespace std;

void count_digit(int n) {
    int count = 0;
    if (n == 0) {
        count = 1; // 0 has 1 digit
    } else {
        count = log10(abs(n)) + 1; // abs() to handle negative numbers
    }
    cout << "Number of digits: " << count << endl;
}
void reverse_number(int n) {
    int reversed = 0;
    while (n != 0) {
        int digit = n % 10;
        reversed = reversed * 10 + digit;
        n /= 10;
    }
    cout << "Reversed number: " << reversed << endl;
}
void palindrome_check(int n) {
    if(n < 0 || (n%10==0 && n!=0)) {
        cout<<"false"<<endl;
        return;
    }
    int rev=0;
    while(n>rev) {
        rev = rev*10 + n%10;
        n /= 10;
    }
    cout<<((n == rev || n == rev/10) ? "true" : "false")<<endl;
}
void gcd_lcm(int a, int b) {
    int ori_a = a, ori_b = b; // Store original values for LCM calculation
    while(b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    cout<< "GCD: " << a << endl;
    long long lcm = (ori_a * ori_b) / a;
    cout<< "LCM: " << lcm << endl; // LCM calculation
}
void armstrong_check(int n) {
    if(n<0) {
        cout<<"false"<<endl;
        return;
    }
    int power = log10(n) + 1, arm = 0, temp = 1, orium = n;

    while(n>0) {
        int temp = 1;
        int mod = n%10;
        for(int i=0;i<power;i++) temp *= mod;
        arm += temp;
        n/=10;
    }
    cout<<(arm == orium ? "true" : "false")<<endl;

}
void factors(int n) {
    vector<int> fact;
    for(int i=1;i*i<=n;i++) {
        if(n%i==0){
            fact.emplace_back(i);
            if(i!=n/i) fact.emplace_back(n/i);
        }
        sort(fact.begin(), fact.end());
    }
    for(auto it: fact) cout<<it<<" ";
}

int main() {
    count_digit(-12313);
    reverse_number(-12313);
    palindrome_check(101101);
    gcd_lcm(12, 15);
    armstrong_check(153);
    factors(28);
    return 0;
}