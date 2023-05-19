#include<iostream>
#include<vector>

#define mod 1000000007
using namespace std;

// Recursive Approach - TLE
long long int CoinComb(int targetSum, int arr[], int n, int curr_indx, vector<vector<int> >& memo){
    if(targetSum == 0){
        return 1;
    }
    if(targetSum < 0){
        return 0;
    }
    if(memo[targetSum][curr_indx] != -1){
        return memo[targetSum][curr_indx];
    }
    long long int count = 0;
    for(int i = curr_indx; i < n; i++){
        count += CoinComb(targetSum - arr[i], arr, n, i, memo);
    }
    memo[targetSum][curr_indx] = count % mod;
    return (memo[targetSum][curr_indx]);
}


int main(){
    int n,x;
    cin >> n >> x;
    int arr[n];
    // vector<vector<int> > memo;
    // for(int i = 0; i < x+1; i++){
    //     vector<int> temp;
    //     for(int j = 0; j < n; j++){
    //         temp.push_back(-1);
    //     }
    //     memo.push_back(temp);
    // }
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    //cout << CoinComb(x, arr, n, 0, memo);

    // Tabulation Approach
    // We are going to use a single array dp which stores every sum from 0 to the targetSum = x
    // As we have to go in order we iterate outside from left to right in the array and keep on updating
    // dp[] with each corresponding targetSum
    // Time Complexity is O(nx)

    vector<int> dp;
    for(int i = 0; i < x+1; i++){
        dp.push_back(0);
    }
    
    // Base Case
    dp[0] = 1;  

    // Recursion changed to Iterative Approach
    for(int i = 0; i < n; i++){
        for(int targetSum = 0; targetSum < x+1; targetSum++){
            if(arr[i] <= targetSum){
                dp[targetSum] += dp[targetSum - arr[i]];
                dp[targetSum] = dp[targetSum] % mod;
            }
        }
    }
    cout << dp[x] << endl;  
}