#include<iostream>
#include<vector>

#define mod 1000000007
using namespace std;

long long int NumWays(int n, long long int* memo){
    if(n == 0){
        return 1;
    }
    if(n < 0){
        return 0;
    }
    if(memo[n] != -1){
        return memo[n];
    }
    long long int count = 0;
    for(int i = 0; i < 6; i++){
        count += (NumWays(n - (i+1), memo));
    }
    memo[n] = count % mod;
    return memo[n];
}

int main(){
    long long int n;
    cin >> n;
    long long int memo[n+1];
    for(int i = 0; i < n+1; i++){
        memo[i] = -1;
    }
    cout << (NumWays(n, memo)) ;
}