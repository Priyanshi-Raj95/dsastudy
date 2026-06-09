# include<iostream>
using namespace std;
//Index of subarrays
void idxsubarray(int n, int *arr){
    cout<<"Index is : "<<endl;
    for(int st=0;st<n;st++){
        for(int end = st;end<n;end++){
            cout<<"("<<st<<","<<end<<") ";
        }
        cout<<endl;
    }
}
// Value of subarrays
void valsubarray(int n, int *arr){
    cout<<"Value of subarray at Index is : "<<endl;
    for(int st=0;st<n;st++){
        for(int end = st;end<n;end++){
            for(int i=st;i<=end;i++){
                cout<<arr[i];
            }
            cout<<" , ";
        }
        cout<<endl;
    }
}
int main(){
    int arr[]={1,2,3,4,5};
    int n=5;
    idxsubarray(n,arr);
    valsubarray(n,arr);
    return 0;
}