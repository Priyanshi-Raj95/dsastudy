#include<iostream>
#include<vector>
#include<queue>
using namespace std;
// ------------HEAP SORT-------------
void heapify(int i, vector<int> &arr, int n){
    int left= 2*i+1;
    int right= 2*i+2;
    int maxIdx=i;

    if(left<n && arr[left] > arr[maxIdx]){
        maxIdx= left;
    }
    if(right<n && arr[right] > arr[maxIdx]){
        maxIdx= right;
    }
    if(maxIdx !=i){
        swap(arr[i], arr[maxIdx]);
        heapify(maxIdx, arr, n);
    }
}
void heapSort(vector<int> &arr){
    int n=arr.size();
    //Step 1: build maxHeap
    for(int i=n/2-1; i>=0;i--){
        heapify(i,arr,n);
    }
    //Step 2: taking elements to their correct position
    for(int i=n-1;i>=0;i--){
        swap(arr[0],arr[i]);
        heapify(0, arr, i);
    }
}
//-----------NEARBY CARS--------------
class Car{
public:
    int idx;
    int distSq;

    Car(int idx, int distSq){
        this->idx= idx;
        this->distSq= distSq;
    }
    bool operator < (const Car &obj) const{
        return this->distSq > obj.distSq;
    }
};
void nearbyCars(vector<pair<int,int>>pos, int k){
    vector<Car>cars;
    for(int i=0;i<pos.size();i++){
        int distsq= (pos[i].first * pos[i].first) + (pos[i].second * pos[i].second);
        cars.push_back(Car(i, distsq));
    }
    priority_queue<Car>pq(cars.begin(), cars.end());
    for(int i=0;i<k;i++){
        cout<<"Car "<<pq.top().idx<<endl;
        pq.pop();
    }
}
//-----------------Connect N Ropes----------
int connectNRopes(vector<int> ropes){
    priority_queue<int, vector<int>, greater<int>>pq(ropes.begin(), ropes.end()); //O(n)
    int cost=0;
    while(pq.size()>1){
        int min1=pq.top();
        pq.pop();
        int min2= pq.top();
        pq.pop();
        cost += min1+ min2;
        pq.push(min1+ min2);
    }
    cout<<"Min cost: "<<cost<<endl;
    return cost;
}
//--------------WEAKEST SOLDIER-------
class Row{
public:
    int count;
    int idx;
    Row(int count, int idx){
        this->count= count;
        this->idx= idx;
    }
    bool operator < (const Row &obj) const{
        if(this->count== obj.count){
            return this->idx> obj.idx;
        }
        return this-> count > obj.count;
    }
};
void weakestSoldier(vector<vector<int>> matrix, int k){
    vector<Row> row;
    for(int i=0;i<matrix.size();i++){
        int count=0;
        for(int j=0;j<matrix[i].size() && matrix[i][j]==1;j++){
            count++;
        }
        row.push_back(Row(count,i));
    }
    priority_queue<Row> pq(row.begin(), row.end());
    for(int i=0;i<k;i++){
        cout<<"Row "<<pq.top().idx<<endl;
        pq.pop();
    }
}
//--------SLIDING WINDOW MAXIMUM------
void slidingWindowMax(vector<int>arr1, int k){
    priority_queue<pair<int, int>>pq;

    for(int i=0;i<k;i++){
        pq.push(make_pair(arr1[i],i));
    }
    cout<<"Output: "<<pq.top().first<<" ";
    for(int i=k;i<arr1.size();i++){
        while(!pq.empty() && pq.top().second <=(i-k)){
            pq.pop();
        }
        pq.push(make_pair(arr1[i],i));
        cout<<pq.top().first<<" ";
    }
    cout<<endl;
}
using namespace std;
int main(){
    vector<int>arr={1,4,2,5,3};
    cout<<"Array before sorting: ";
    for(int i=0;i<arr.size();i++){
         cout<<arr[i]<<" ";
    }
    cout<<endl;
    heapSort(arr);
     cout<<"Sorted array: ";
    for(int i=0;i<arr.size();i++){
         cout<<arr[i]<<" ";
    }
    cout<<endl<<"----------------------"<<endl;
    // -------Nearby Cars--------
    vector<pair<int,int>>pos;
    pos.push_back(make_pair(3,3));
    pos.push_back(make_pair(5,-1));
    pos.push_back(make_pair(-2,4));
    int k=2;
    nearbyCars(pos, k);
    cout<<endl<<"----------------------"<<endl;
    //--------Connect N Ropes------
    vector<int> ropes= {4,3,2,6};
    connectNRopes(ropes);
    cout<<endl<<"----------------------"<<endl;
    //-------Weakest Soldier--------
    vector<vector<int>> matrix= {{1,0,0,0},
                                  {1,1,1,1},
                                  {1,0,0,0},
                                  {1,0,0,0}
                                };
    weakestSoldier(matrix,2);     
    cout<<endl<<"----------------------"<<endl;         
    //-------Sliding Window maximum------
    vector<int>arr1= {1,3,-1,-3,5,3,6,7};
    int K=3;
      slidingWindowMax(arr1, K);         
    return 0;
}