#include <bits/stdc++.h>
using namespace std;

void pairs() {
    pair<int, int> p = {1, 3};
    cout<<p.first<<" "<<p.second<<endl;
    pair<int, pair<int, int>> p1 = {1, {3, 4}};
    cout<<p1.first<<" "<<p1.second.first<<" "<<p1.second.second<<endl;
    pair<int, int> arr[] = {{1, 2}, {3, 4}, {5, 6}};
    cout<<arr[1].second<<endl;
}
void vectors() {
    vector<int> v;
    v.push_back(1);
    v.emplace_back(2);

    vector<pair<int,int>> vec;
    vec.push_back({1,3});
    vec.emplace_back(2,4);

    vector<int> v1(5,50); // 5 elements with value 50
    vector<int> v2(5); // 5 elements with default value 0

    vector<int> v3(v1);

    vector<int>::iterator it = v2.begin();
    cout<<*(it)<<endl;
    it++;
    cout<<*(it)<<endl;

    vector<int> v4 = {1,2,3,4,5};
    
    vector<int>::iterator it1 = v4.begin();
    cout<<*(it1)<<" "<<*(it1+1)<<endl;
    
    vector<int>::iterator it2 = v4.end();
    cout<<*(it2)<<" "<<*(it2-1)<<endl;

    cout<<v4[3]<<" "<<v4.at(3)<<endl;
    cout<<v4.back()<<endl;

    for(vector<int>::iterator it=v4.begin(); it!=v4.end(); it++) {
        cout<<*(it)<<" ";
    }
    cout<<endl;
    for(auto it=v4.begin(); it!=v4.end(); it++) {
        cout<<*(it)<<" ";
    }
    cout<<endl;
    for(auto it: v4){
        cout<<it<<" ";
    }
    cout<<endl;

    vector<int> v5(v4);
    
    v5.push_back(6);
    for(auto it: v5){
        cout<<it<<" ";
    } 
    cout<<endl;

    v5.erase(v5.begin()+2); // erase 3rd element
    for(auto it: v5){
        cout<<it<<" ";
    } 
    cout<<endl;
    
    v5.erase(v5.begin()+2, v5.begin()+4); // erase from 3rd to 4th element
    for(auto it: v5){
        cout<<it<<" ";
    } 
    cout<<endl;
    
    v5.insert(v5.begin(),23);
    for(auto it: v5){
        cout<<it<<" ";
    } 
    cout<<endl;
    
    v5.insert(v5.begin()+1,2,56);
    for(auto it: v5){
        cout<<it<<" ";
    } 
    cout<<endl;

    cout<<v5.size()<<endl;
    v5.pop_back();
    cout<<v5.size()<<endl;
    cout<<v5.empty()<<endl;
    v5.clear();
    cout<<v5.size()<<endl;
    cout<<v5.empty()<<endl;

    vector<int> a = {1,2,3};
    vector<int> b = {4,5,6};
    swap(a,b);
    for(auto it: a){
        cout<<it<<" ";
    }
    cout<<endl;
    for(auto it: b){
        cout<<it<<" ";
    }
    cout<<endl;
}
void lists() {
    list<int> ls;

    ls.push_back(2);        // {2}
    ls.emplace_back(4);     // {2, 4}

    ls.push_front(5);       // {5, 2, 4}
    ls.emplace_front(6);    // {6, 5, 2, 4}
    for(auto it: ls) {
        cout<<it<<" ";
    }

    // rest functions same as vector:
    // begin, end, rbegin, rend, clear, insert, size, swap
}
void Deques() {
    deque<int> dq;

    dq.push_back(1);      // {1}
    dq.emplace_back(2);   // {1, 2}

    dq.push_front(4);     // {4, 1, 2}
    dq.emplace_front(3);  // {3, 4, 1, 2}

    dq.pop_back();        // {3, 4, 1}
    dq.pop_front();       // {4, 1}

    dq.back();            // last element
    dq.front();           // first element

    // rest functions same as vector:
    // begin, end, rbegin, rend, clear, insert, size, swap
}
void stacks(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.emplace(4);
    
    stack<int> s1(s); // copy stack s to s1
    
    cout<<s.top()<<endl; // 4
    s.pop();
    cout<<s.top()<<endl; // 3
    cout<<s.size()<<endl;
    cout<<s.empty()<<endl;
    s.swap(s1);
}
void queues(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.emplace(4);

    queue<int> q1(q); // copy queue q to q1

    cout<<q.front()<<endl; // 1
    cout<<q.back()<<endl;  // 4
    q.back()+=5;
    cout<<q.back()<<endl;  // 9
    q.pop();
    cout<<q.front()<<endl; // 2
    cout<<q.size()<<endl;
    cout<<q.empty()<<endl;
    q.swap(q1);
}
void priority_queues(){
    priority_queue<int> pq; // max heap
    pq.push(5);
    pq.push(2);
    pq.push(8);
    pq.emplace(10);

    cout<<pq.top()<<endl; // 10
    pq.pop();
    cout<<pq.top()<<endl; // 8

    priority_queue<int, vector<int>, greater<int>> minheap; // min heap
    minheap.push(5);
    minheap.push(2);
    minheap.push(8);
    minheap.emplace(10);

    cout<<minheap.top()<<endl; // 2
    minheap.pop();
    cout<<minheap.top()<<endl; // 5
}
void sets() {
    set<int> st;
    st.insert(1);
    st.emplace(2);
    st.insert(2);
    st.insert(4);
    st.insert(3);

    auto it1 = st.find(3);
    auto it2 = st.find(6);

    st.erase(5);

    cout<<st.count(2)<<endl;
    cout<<st.count(6)<<endl;

    auto it3 = st.find(3);
    st.erase(it3);

    auto it4 = st.find(2);
    auto it5 = st.find(4);
    st.erase(it4, it5); // erases from 2 to 4 (4 not included)
    
    auto it6 = st.lower_bound(2);
    auto it7 = st.upper_bound(4);
}
void multisets() {
    multiset<int> ms;
    ms.insert(1);
    ms.insert(1);
    ms.insert(2);
    ms.insert(2);
    ms.insert(2);
    ms.insert(2);
    ms.insert(3);

    cout<<ms.count(1)<<endl; // 2

    ms.erase(1); // erases all occurrences of 1

    auto it = ms.find(2);
    ms.erase(it); // erases only one occurrence of 2
    ms.erase(ms.find(2),ms.find(2)); // erases all occurrences of 2
}
void unorderedsets() {
    unordered_set<int> us;
    us.insert(1);
    us.insert(2);
    us.insert(3);
    us.insert(4);
    us.insert(5);

    auto it = us.find(3);
    auto it2 = us.find(6);

    us.erase(5);

    cout<<us.count(2)<<endl;
    cout<<us.count(6)<<endl;
}
void maps() {
    map<int,int> mapp;
    mapp[1] = 23;
    mapp.emplace(2,45);
    mapp.insert({3,45});

    for(auto mp : mapp) {
        cout<<mp.first<<":"<<mp.second<<endl;
    }
    cout<<mapp[1]<<endl;
    cout<<mapp[6]<<endl;

    auto it = mapp.find(3);
    cout<<it->second<<endl;

    // cout<<mapp.find(5)->second<<endl; // This crashes if key doesn't exist
    
    // rest functions same as sets
}
void multimaps(){
    multimap<int,int> mmapp;
    mmapp.insert({1,23});
    mmapp.insert({1,45});
    mmapp.insert({2,34});
    mmapp.insert({2,56});

    for(auto mp : mmapp) {
        cout<<mp.first<<":"<<mp.second<<endl;
    }

    cout<<mmapp.count(1)<<endl; // 2

    mmapp.erase(1); // erases all key-value pairs with key 1

    auto it = mmapp.find(2);
    mmapp.erase(it); // erases only one key-value pair with key 2
}
void unorderedmaps(){
    unordered_map<int,int> umapp;
    umapp[1] = 23;
    umapp.emplace(2,45);
    umapp.insert({3,45});

    for(auto mp : umapp) {
        cout<<mp.first<<":"<<mp.second<<endl;
    }
    cout<<umapp[1]<<endl;
    cout<<umapp[6]<<endl;

    auto it = umapp.find(3);
    cout<<it->second<<endl;

    // cout<<umapp.find(5)->second<<endl; // This crashes if key doesn't exist
    
    // rest functions same as unordered sets
}
bool comp(pair<int,int> a, pair<int,int> b) {
        if(a.second < b.second) return true;
        else if(a.second > b.second) return false;
        else {
            if(a.first > b.first) return true;
            else return false;
        }
    }
void functions1() {
        vector<int> v = {4,3,1,5,2};
        
        for (auto it: v) {
            cout<<it<<" ";
        }
        cout<<endl;
        
        //reverse
        reverse(v.begin(), v.end());
        for (auto it: v) {
            cout<<it<<" ";
        }
        cout<<endl;
        
        //sort
        sort(v.begin(), v.end()); // ascending
    for (auto it: v) {
        cout<<it<<" ";
    }
    cout<<endl;
   
    sort(v.begin(), v.end(), greater<int>()); // descending
    for (auto it: v) {
        cout<<it<<" ";
    }
    cout<<endl;
    
    pair<int,int> arr[] = {{1,2},{5,3},{3,4},{6,4}};
    
    sort(arr,arr+4);
    for(auto it2:arr) {
        cout<<it2.first<<":"<<it2.second<<endl;
    }
    // if we want to sort based on out wish then we use boolean function
    // example: sort based on second element of pair in ascending order
    // if second element is same then based on first element in descending order
    
    sort(arr,arr+3,comp); //self defined boolean function
    for(auto it2: arr) {
        cout<<it2.first<<":"<<it2.second<<endl;
    }

    //for returning the no. of set bits in binary representation of a no.
    int n = 13; // binary representation is 1101
    cout << __builtin_popcount(n) << endl; // output: 3
     long long m = 1234567890123;
    cout << __builtin_popcountll(m) << endl; // output: 7
    
    //permutations
    string s = "231"; // elements are not sorted so not all permutations will be printed
    do {
        cout<<s<<" ";
    } while(next_permutation(s.begin(), s.end()));
    cout<<endl;

    sort(s.begin(), s.end()); // sorting first to get all permutations
    do {
        cout<<s<<" ";
    } while(next_permutation(s.begin(), s.end()));
    cout<<endl;
    
    //min and max
    int a = 5, b = 10;
    cout << min(a, b) << endl;
    cout << max(a, b) << endl;

    int arr1[] = {1, 5, 3, 9, 2};
    cout << *max_element(arr1, arr1 + sizeof(arr1)/sizeof(arr1[0])) << endl;
    cout << *min_element(arr1, arr1 + sizeof(arr1)/sizeof(arr1[0])) << endl;

}

int main() {
    cout<<"Pairs Example:\n";
    pairs();
    cout<<endl;
    cout<<"Vectors Example:\n";
    vectors();
    cout<<endl;
    cout<<"Lists Example:\n";
    lists();
    cout<<endl;
    cout<<"Deques Example:\n";
    Deques();
    cout<<endl;
    cout<<"Stacks Example:\n";
    stacks();
    cout<<endl;
    cout<<"Queues Example:\n";
    queues();
    cout<<endl;
    cout<<"Priority Queues Example:\n";
    priority_queues();
    cout<<endl;
    cout<<"Sets Example:\n";
    sets();
    cout<<endl;
    cout<<"Multisets Example:\n";
    multisets();
    cout<<endl;
    cout<<"Unordered Sets Example:\n";
    unorderedsets();
    cout<<endl;
    cout<<"Maps Example:\n";
    maps();
    cout<<endl;
    cout<<"Multimaps Example:\n";
    multimaps();
    cout<<endl;
    cout<<"Unordered Maps Example:\n";
    unorderedmaps();
    cout<<endl;
    cout<<"Functions Example:\n";
    functions1();
    return 0;
}