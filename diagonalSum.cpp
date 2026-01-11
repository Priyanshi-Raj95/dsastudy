#include <iostream>
using namespace std;

int diagonalSum(int matrix[][4],int n){
    int sum = 0;
    //O(n^2)
    for(int i =0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                sum +=matrix[i][j];
            }
            else if(j== n-i-1){
                sum +=matrix[i][j];
            }
        }
    }
    cout << "Sum = "<<sum<<endl;
    return sum;

}
int diagonalSum1(int matrix[][4],int n){
    int sum1 = 0;
    //O(n)
    for(int i =0;i<n;i++){
        sum1 +=matrix[i][i];
        if(i != n-i-1){
            sum1 +=matrix[i][n-i-1];
        }
    }
    cout<<"sum = "<<sum1<<endl;
    return sum1;
}
int main (){
    int matrix[4][4] ={ {1,2,3,4},
                        {5,6,7,8},
                        {9,10,11,12},
                        {13,14,15,16}
    };
    diagonalSum(matrix,4);
    return diagonalSum1(matrix,4);

    return 0;
}