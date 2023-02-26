#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    long long int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    long long int prefix_sum[n+1];
    prefix_sum[0] = 0;
    for(int i = 1; i < n+1; i++){
        prefix_sum[i] = prefix_sum[i-1] + arr[i-1];
    }
    long long int min = prefix_sum[1];
    long long int max = prefix_sum[1];
    for(int i = 0; i < n+1; i++){
        if(prefix_sum[i] < min){
            min = prefix_sum[i];
        }
        if(prefix_sum[i] > max){
            max = prefix_sum[i];
        }
    }
    cout << max-min << endl;
    
}