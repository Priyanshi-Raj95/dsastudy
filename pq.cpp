#include<iostream>
#include<queue>
using namespace std;

class heap{
    vector<int>vec;
public:
    void push(int val){
        vec.push_back(val);
        int x= vec.size()-1; //child Index
        int parIdx= (x-1)/2;

        while(parIdx>=0 && vec[x] > vec[parIdx]){
            swap(vec[x], vec[parIdx]);
            x=parIdx;
            parIdx=(x-1)/2;
        }
    }
    void heapify(int i){
        if(i>=vec.size()){
            return;
        }
        int l= 2*i+1;
        int r= 2*i+2;
        int maxIdx=i;
        if(l<vec.size()&& vec[l]>vec[maxIdx]){
            maxIdx=l;
        }
        if(r<vec.size()&& vec[r]>vec[maxIdx]){
            maxIdx=r;
        }
        swap(vec[i],vec[maxIdx]);
        if(maxIdx !=i){
            heapify(maxIdx);
        }
    }
    void pop(){
        int x=vec.size()-1;
        swap(vec[0], vec[x]);
        vec.pop_back();
        heapify(0);
    }
    int top(){
        return vec[0];
    }
    bool empty(){
        return vec.size() ==0;
    }
};
int main(){
    priority_queue<int, vector<int>,greater<int>>pq;
    pq.push(5);
    pq.push(10);
    pq.push(4);
    pq.push(6);
    pq.push(9);
    pq.push(7);
    while(!pq.empty()){
        cout<<"Top of priority queue: "<<pq.top()<<endl;
        pq.pop();
    }
    heap Heap;
    Heap.push(50);
    Heap.push(20);
    Heap.push(90);
    while(!Heap.empty()){
        cout<<"Top of Heap: "<<Heap.top()<<endl;
        Heap.pop();
    }
    return 0;
} 