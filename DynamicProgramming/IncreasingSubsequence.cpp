#include<iostream>
#include<vector>

using namespace std;

int LIS_Tabulation(int n, long long int arr[]){
    int dp[n];
    for(int i = 0; i < n; i++){
        dp[i] = 1;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(arr[j] < arr[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int maxx = -1;
    for(int i = 0; i < n; i++){
        if(dp[i] > maxx){
            maxx = dp[i];
        }
    }
    return maxx;
}

int lis_binarysearch(int n, long long int arr[]){
    vector<long long int> temp;
    temp.push_back(arr[0]);
    for(int i = 1; i < n; i++){
        if(arr[i] > temp[((int)temp.size()) - 1]){
            temp.push_back(arr[i]);
        }
        else{
            //Binary Search
            int l = -1;
            int r = temp.size() - 1;
            while(r - l > 1){
                int mid = (l+r)/2;
                if(temp[mid] >= arr[i]){
                    r = mid;
                }
                else{
                    l = mid;
                }
            }
            temp[r] = arr[i];
        }
    }
    return temp.size();
}


int main(){
    int n;
    cin >> n;
    long long int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << lis_binarysearch(n, arr) << endl;
}