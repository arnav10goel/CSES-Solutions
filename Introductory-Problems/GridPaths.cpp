#include<iostream>
#include<string>
#include<vector>

using namespace std;

int matrix[7][7];

int dp[7][7][48];

int Paths(string in, int row, int col, int indx){
    if(indx == in.length()){
        return 0;
    }
    if(row < 0 || col < 0){
        return 0;
    }
    if(row > 6 || col > 6){
        return 0;
    }
    if(row == 6 && col == 6){
        return 1;
    }
    if(dp[row][col][indx] != -1){
        return dp[row][col][indx];
    }
    if(in[indx] == 'D'){
        dp[row][col][indx] = Paths(in, row+1, col, indx+1);
        return dp[row][col][indx];
    }
    else if(in[indx] == 'U'){
        dp[row][col][indx] = Paths(in, row-1, col, indx+1);
        return dp[row][col][indx];
    }
    else if(in[indx] == 'L'){
        dp[row][col][indx] = Paths(in, row, col-1, indx+1);
        return dp[row][col][indx];
    }
    else if(in[indx] == 'R'){
        dp[row][col][indx] = Paths(in, row, col+1, indx+1);
        return dp[row][col][indx];
    }
    else{
        int count = 0;
        count = Paths(in, row+1, col, indx+1) + Paths(in, row-1, col, indx+1) + Paths(in, row, col-1, indx+1) + Paths(in, row, col+1, indx+1);
        dp[row][col][indx] = count;
        return count;
    }
    
}

int main(){
    string in;
    cin >> in;
    cout << Paths(in, 0, 0, 0);
    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 7; j++){
            for(int k = 0; k < 48; k++){
                dp[i][j][k] = -1;
            }
        }
    }

}