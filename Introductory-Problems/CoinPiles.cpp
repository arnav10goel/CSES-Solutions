#include<iostream>
#include<string>
#include<vector>

using namespace std;

// Recursive Approach - TLE
int TwoCoins(int a, int b, vector<vector<int> >& dp){
    if(a == 0 && b == 0){
        return 1;
    }
    if((a == 0 && b != 0) || (a != 0 && b == 0)){
        return 0;
    }
    if(a == 1 && b == 1){
        return 0;
    }
    if(a < 0 || b < 0){
        return 0;
    }
    if(dp[a][b] != -1){
        return dp[a][b];
    }
    return dp[a][b] = TwoCoins(a-1,b-2, dp) || TwoCoins(a-2,b-1, dp);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        long long int a,b;
        cin >> a >> b;
        
        // Easier method is by normal math
        // Our possible moves are: Remove 2 from left and 1 from right OR 2 from right and 1 from left
        // Let X be total number of moves of type 1 and Y be total number of moves of type 2
        // a - 2X - Y = 0
        // b - X - 2Y = 0
        // Y = (2b-a)/3
        // X = (2a-b)/3
        // Thus for one condition (a+b) must be divisible by 3
        //If the size of one pile is larger than twice the other pile, when one is empty the other will still have coins.

        if(max(a,b) > 2*min(a,b)){
            cout << "NO" <<  endl;
        }
        else{
            if(abs(2*b-a) % 3 == 0 && abs(2*a - b) % 3 == 0){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
        
    }
}