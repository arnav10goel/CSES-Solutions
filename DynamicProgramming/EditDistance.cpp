#include<iostream>
#include<vector>
#include<string>

#define mod 1000000007
using namespace std;

// Using Memoisation (gives TLE in CSES)
int EditDistance(string s1, string s2, int indx1, int indx2, vector<vector<int> >& dp){
    if(indx1 < 0){
        return indx2+1;
    }
    if(indx2 < 0){
        return indx1+1;
    }
    if(dp[indx1][indx2] != -1){
        return dp[indx1][indx2];
    }
    if(s1[indx1] == s2[indx2]){
        return EditDistance(s1, s2, indx1-1, indx2-1, dp);
    }
    else{
        int insert = EditDistance(s1, s2, indx1, indx2-1, dp);
        int replace = EditDistance(s1, s2, indx1-1, indx2-1, dp);
        int remove = EditDistance(s1, s2, indx1-1, indx2, dp);
        dp[indx1][indx2] = 1 + min(remove, min(insert, replace));
        return dp[indx1][indx2];
    }
}

int main(){
    string s1,s2;
    cin >> s1;
    cin >> s2;
    vector<vector<int> > dp;
    for(int i = 0; i < s1.length(); i++){
        vector<int> temp;
        for(int j = 0; j < s2.length(); j++){
            temp.push_back(-1);
        }
        dp.push_back(temp);
    }

    //cout << EditDistance(s1, s2, s1.length()-1, s2.length()-1, dp) << endl;
    // Tabulation Approach
    int n = s1.length();
    int m = s2.length();
    int tabulation[n+1][m+1];

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            tabulation[i][j] = 0;
        }
    }
    for(int i = 0; i <= n; i++){
        tabulation[i][0] = i;
    }
    for(int j = 0; j <= m; j++){
        tabulation[0][j] = j;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s1[i-1] == s2[j-1]){
                tabulation[i][j] = tabulation[i-1][j-1];
            }
            else{
                tabulation[i][j] = 1 + min(tabulation[i-1][j], min(tabulation[i-1][j-1], tabulation[i][j-1]));
            }
        }
    }
    cout << tabulation[n][m] << endl;
}