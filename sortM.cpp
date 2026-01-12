#include <iostream>
#include <climits>
using namespace std;

//O(n+m)
// if(n>>>>m) then O(n)
// if(n<<<<m) then O(m)
void sortM(int mtrx[][4],int n,int m,int key){
    //Brute force
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mtrx[i][j] == key){
                cout<<"key = "<<i<<","<<j;
                break;

            }
        }

    }
    cout<<endl;
}

void search(int matrix[][4],int n,int m,int key){
    //staircase approach
    int i=0,j=m-1;
    while(i<n && j>=0){
        if(matrix[i][j] == key){
            cout<<"Key found at ("<<i<<","<<j<<")\n";
            break;
        }
        else if(matrix[i][j] <key){
            i++;
        }
        else{
            j--;
        }
    }
}
int main(){ 
    int matrix[4][4] ={{10,20,30,40},
                       {15,25,35,45},
                       {27,29,37,48},
                       {32,33,39,50}};
    
    sortM(matrix,4,4,33);
    search(matrix,4,4,33);
    return 0;
}  