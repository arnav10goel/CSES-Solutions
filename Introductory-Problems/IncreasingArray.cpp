#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    unsigned long long int n;
    cin >> n;
    unsigned long long int arr[n];
    for(unsigned long long int i = 0 ; i < n; i++){
        cin >> arr[i];
    }
    unsigned long long int res = 0;
    for(unsigned long long int i = 1 ; i < n; i++){
        if(arr[i-1] > arr[i]){
            res += arr[i-1] - arr[i];
            arr[i] += arr[i-1] - arr[i];
        }
    }
    cout << res << endl;
}