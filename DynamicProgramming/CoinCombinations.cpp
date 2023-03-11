#include<iostream>
#include<vector>

#define mod 1000000007
using namespace std;

long long int CoinComb(int targetSum, int arr[], int n, int* memo){
    if(targetSum == 0){
        return 1;
    }
    if(targetSum < 0){
        return 0;
    }
    if(memo[targetSum] != -1){
        return memo[targetSum];
    }
    long long int count = 0;
    for(int i = 0; i < n; i++){
        count += CoinComb(targetSum - arr[i], arr, n, memo);
    }
    memo[targetSum] = count % mod;
    return (memo[targetSum]);
}

int main(){
    int n,x;
    cin >> n >> x;
    int arr[n];
    int memo[x+1];
    for(int i = 0; i < x+1; i++){
        memo[i] = -1;
    }
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << CoinComb(x, arr, n, memo);
}