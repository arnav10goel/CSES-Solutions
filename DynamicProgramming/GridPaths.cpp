#include<iostream>
#include<vector>

#define mod 1000000007
using namespace std;

char grid[1001][1001];

int GridPaths(int m, int n, vector<vector<long long int> > &dp){
    if(m == 1 && n == 1){
        return 1;
    }
    if(m < 1 || n < 1){
        return 0;
    }
    if(dp[m-1][n-1] != -1){
        return dp[m-1][n-1];
    }
    int count = 0;
    if(grid[m-1][n] != '*'){
        count += GridPaths(m-1, n, dp);
    }
    if(grid[m][n-1] != '*'){
        count += GridPaths(m, n-1, dp);
    }
    dp[m-1][n-1] = count % mod;
    return count % mod;

}

int main(){
    int n;
    cin >> n;
    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < n+1; j++){
            cin >> grid[i][j];
        }
    }
    if(grid[n][n] == '*'){
        cout << 0;
        return 0;
    }
    vector<vector<long long int> > dp(n, vector< long long int>(n, -1));
    cout << GridPaths(n, n, dp);
}