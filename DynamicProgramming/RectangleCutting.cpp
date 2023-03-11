#include<iostream>
#include<vector>

#define mod 1000000000L

using namespace std;

int dp[501][501];

int RectangleCuts(int a, int b){
    if(a == 0 || b == 0){
        return -1;
    }
    if(a == b){
        return 0;
    }
    if(dp[a][b] != -1){
        return dp[a][b];
    }

    int temp = mod;
    for(int i = 1; i <= a; i++){
        temp = min(temp, 1 + RectangleCuts(i, b) + RectangleCuts(a-i, b));
    }
    for(int i = 1; i <= b; i++){
        temp = min(temp, 1 + RectangleCuts(a, i) + RectangleCuts(a, b-i));
    }
    dp[a][b] = temp;
    return dp[a][b];

}

int main(){
    int a,b;
    cin >> a >> b;
    for(int i = 0; i < 501; i++){
        for(int j = 0; j < 501; j++){
            dp[i][j] = -1;
        }
    }
    cout << RectangleCuts(a, b) << endl;
}