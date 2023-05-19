#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    long long int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    sort(arr, arr+n);
    long long int avg = arr[n/2];
    long long int res = 0;
    for(int i = 0; i < n; i++){
        res += abs(avg-arr[i]);
    }
    cout << res << endl;

}