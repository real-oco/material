#include <bits/stdc++.h>
using namespace std;

class Heap{
public:
vector<int> vec;
Heap(){}

// Inserts into the heap    
void insert(int val){
vec.push_back(val);
int idx=vec.size()-1;
int parent=(idx-1)/2;
while(idx>0 && vec[parent]>vec[idx]){
    swap(vec[parent],vec[idx]);
    idx=parent;
    parent=(idx-1)/2;
}
}
// Prints the heap
void print(){
    for(auto it : vec) cout<<it<<endl;
}

void heapifyDown(int i){
    int n=vec.size();
    if(i>=n) return;
    int left=2*i+1;
    int right=2*i+2;
    int smallest=i;
    if(left<n && vec[i]>vec[left]){
     smallest=left;
    }
    if(right<n && vec[i]>vec[right]){
        smallest=right;
    }
    if(smallest!=i){
        swap(vec[smallest],vec[i]);
        heapifyDown(smallest);
    }
    return;
}

void removeMin(){
    int n=vec.size();
    int lastVal=vec[n-1];
    vec[0]=lastVal;
    vec.pop_back();
    heapifyDown(0);
    //heapyfy down
}
};

int main(){
    Heap h;
    h.insert(2);
    h.insert(3);
    h.insert(1);
    h.insert(8);
    h.removeMin();
    h.print();
    return 0;
}