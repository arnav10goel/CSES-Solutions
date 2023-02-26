#include<iostream>
#include<vector>

#define mod 1000000007
using namespace std;

long long int my_min(long long int a, long long int b){
    if(a < b){
        return a;
    }
    else{
        return b;
    }
}

long long int mincoins(int sum, int arr[], int n, long long int* memo){
    if(sum == 0){
        return 0;
    }
    if(sum < 0){
        return mod;
    }
    if(memo[n] != -1){
        return memo[n];
    }
    int min_count = mod;
    for(int i = 0; i < n; i++){
        min_count = my_min(mincoins(sum - arr[i], arr, n, memo), min_count);
    }
    memo[n] = min_count + 1;
    return memo[n];
}

int main(){
    int n,x;
    cin >> n >> x;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    long long int memo[n+1];
    for(int i = 0; i < n+1; i++){
        memo[i] = -1;
    }
    long long int res = mincoins(x, arr, n, memo);
    if(res == mod + 1){
        cout << -1;
    }
    else{
        cout << res;
    }
}