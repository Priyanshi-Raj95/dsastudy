#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Heap{
    vector<int>v;
public:
    void push(int val){
        v.push_back(val); 
        int x= v.size()-1; //child Index
        int parIdx=(x-1)/2; //parent index
        while(parIdx>=0 && v[x]>v[parIdx]){ //O(logn)
            swap(v[x], v[parIdx]);
            x=parIdx;
            parIdx=(x-1)/2;
        }
    }
    void heapify(int i){ //i =parIdx
        if(i>=v.size()){
            return;
        }
        int leftIdx= 2*i+1;
        int rightIdx= 2*i +2;
        int maxIdx=i;
        if(leftIdx<v.size() && v[leftIdx]>v[maxIdx]){
            maxIdx=leftIdx;
        }
        if(rightIdx<v.size() && v[rightIdx]>v[maxIdx]){
            maxIdx=rightIdx;
        }
        swap(v[i],v[maxIdx]);
        if(maxIdx!=i){ //swapping with child node
            heapify(maxIdx);
        }
    }
    void pop(){
        swap(v[0], v[v.size()-1]);
        v.pop_back();
        //fix heap
        heapify(0); //O(logn)

    }
    int top(){
        return v[0];
    }
    bool empty(){
        return v.size()==0;
    }
};
int main(){
    Heap heap;
    heap.push(3);
    heap.push(8);
    heap.push(6);
    heap.push(4);
    cout<<"Top after pushing elements= "<<heap.top()<<endl;
    while(!heap.empty()){
        cout<<"Top = "<<heap.top()<<endl;
        heap.pop();
    }
    return 0;
}