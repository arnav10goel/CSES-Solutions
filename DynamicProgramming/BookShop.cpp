#include<iostream>
#include<vector>

#define mod 1000000007
using namespace std;

// Like the knapsack problem

// Recursive Approach
int maxPages(int prices[], int pages[], int n, int MaxPrice, vector<vector<int> >& dp){
    if(n == 0){
        if(prices[n] <= MaxPrice){
            return pages[n];
        }
        else{
            return 0;
        }
    }
    if(dp[MaxPrice][n] != -1){
        return dp[MaxPrice][n];
    }
    int val = 0;
    val = maxPages(prices, pages, n-1, MaxPrice, dp);

    if(prices[n] <= MaxPrice){
        val = max(val, pages[n] + maxPages(prices, pages, n-1, MaxPrice-prices[n], dp));
    }
    dp[MaxPrice][n] = val;
    return val;
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,x;
    cin >> n >> x;
    int prices[n];
    int pages[n];
    
    for(int i = 0; i < n; i++){
        cin >> prices[i];
    }
    for(int i = 0; i < n; i++){
        cin >> pages[i];
    }
    int dp[n][x+1];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < x+1; j++){
            dp[i][j] = 0;
        }
    }
    for(int p = prices[0]; p <= x; p++){
        dp[0][p] = pages[0];
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j < x+1; j++){
            // Not take
            int val = 0 + dp[i-1][j];
            if(prices[i] <= j){
                val = max(val, pages[i] + dp[i-1][j - prices[i]]);
            }
            dp[i][j] = val;
        }
    }
    cout << dp[n-1][x] << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < x+1; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    //cout << maxPages(prices, pages, n-1, x, dp) << endl; // Note dp is a vector here
}