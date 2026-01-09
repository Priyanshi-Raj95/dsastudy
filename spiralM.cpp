#include <iostream>
using namespace std;

void spiralM(int matrix[] [4], int n,int m){
    int srow =0,scol = 0;//starting row and starting column
    int erow = n-1,ecol = m-1;

    while (srow <= erow && scol <=ecol){
        //top
        for(int i = scol;i<=ecol;i++){
            cout<< matrix[srow][i]<<" ";
        }
        //right
        for(int j = srow+1;j<=erow;j++){
            cout<< matrix[j][ecol]<<" ";
        }
        //bottom
        for(int k = ecol-1;k>=scol;k--){
            if(srow == erow){
                break;
            }
            cout<< matrix[erow][k]<<" ";
        }
        //left
        for(int l = erow-1;l>=srow+1;l--){
            if(scol == ecol){
                break;
            }
            cout<< matrix[l][scol]<<" ";
        }
        srow++;scol++;
        erow--;ecol--;
    }
    cout<<endl;
}
int main (){
    int matrix[4][4] ={ {1,2,3,4},
                        {5,6,7,8},
                        {9,10,11,12},
                        {13,14,15,16}
    };
    spiralM(matrix,4,4);

    return 0;
}