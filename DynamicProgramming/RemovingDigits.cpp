#include<iostream>
#include<vector>

#define mod 1000000007
using namespace std;

int RemoveDigits(int n, int* dp){
    if(n == 0){
        return 0;
    }
    if(n < 0){
        return mod;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    vector<int> digits;
    int temp = n;
    while(temp != 0){
        digits.push_back(temp % 10);
        temp = temp/10;
    }
    int res = mod;
    for(int i = 0; i < digits.size(); i++){
        if(digits[i] != 0){
            res = min(res, RemoveDigits(n - digits[i], dp));
        }
    }
    dp[n] = res + 1;
    return dp[n];
}

int main(){
    int n;
    cin >> n;
    int dp[n+1];
    for(int i = 0; i < n+1; i++){
        dp[i] = -1;
    }
    cout << RemoveDigits(n, dp) << endl;
}