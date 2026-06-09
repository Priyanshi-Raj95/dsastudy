#include<iostream>
#include<climits>
using namespace std;

void stock(int *prices, int n){
    int bestBuy[100000];
    bestBuy[0] = INT_MAX;
    for(int i=1 ;i<n;i++){
        bestBuy[i]= min(bestBuy[i-1],prices[i-1]);
        
    }
    int maxProfit = 0;
    for(int i=0;i<n;i++){
        int currprofit = prices[i]-bestBuy[i];
        maxProfit= max(maxProfit,currprofit);
    }
    cout<<"maximum profit = "<<maxProfit<<endl;
}
int main(){
    int prices[] = {7,1,5,3,6,4};
    int n=6;
    stock(prices,n);
    return 0;
}