#include<iostream>
#include<vector>
#include<unordered_set>

#define mod 1000000007
using namespace std;

// Accepted with Memoisation
// Logic is subsequences can max sum upto the sum of elements of an array (all are non negative)
// So we iterate and check if each sum from 1 to SUM_MAX is possible and return a bool for the same

int sum(int arr[], int indx, int target_sum, vector<vector<int> >& dp){
    if(target_sum < 0){
        return 0;
    }
    if(target_sum == 0){
        return 1;
    }
    if(indx == 0){
        if(arr[indx] == target_sum){
            return 1;
        }
        else{
            return 0;
        }
    }
    if(dp[indx][target_sum] != -1){
        return dp[indx][target_sum];
    }

    dp[indx][target_sum] = sum(arr, indx-1, target_sum-arr[indx], dp) || sum(arr, indx-1, target_sum, dp);
    return dp[indx][target_sum];
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<vector<int> > res;
    
    int target_sum = 0;
    for(int i = 0; i < n; i++){
        target_sum += arr[i];
    }
    bool sum_checker[target_sum+1];

    vector<vector<int> > dp;
    for(int i = 0; i < n; i++){
        vector<int> temp;
        for(int j = 0; j < target_sum+1; j++){
            temp.push_back(-1);
        }
        dp.push_back(temp);
    }
    // All subsequences can sum up from 1 to target_sum which is the sum of the elements of the array
    int count = 0;
    for(int i = 1; i < target_sum+1; i++){
        sum_checker[i] = sum(arr, n-1, i, dp);
        if(sum_checker[i] == 1){
            count += 1;
        }
    }
    cout << count << endl;
    for(int i = 1; i < target_sum+1; i++){
        if(sum_checker[i] == 1){
            cout << i << " ";
        }
    }
    return 0;
}