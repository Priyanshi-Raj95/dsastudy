#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int>A={4,1,8,7};
    vector<int>B={2,3,5,6};

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    cout<<"After sorting A : ";
    for(int i=0;i<A.size();i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
    cout<<"After sorting B : ";
    for(int i=0;i<B.size();i++){
        cout<<B[i]<<" ";
    }
    cout<<endl;
    int absDiff=0;
    for(int i=0;i<A.size();i++){
        absDiff+=abs(A[i]-B[i]);
    }
    cout<<"Min absolute difference pair sum = "<<absDiff<<endl;
    return 0;
}