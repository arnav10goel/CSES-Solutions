#include<iostream>
using namespace std;

int main(){
    long long int n,k;
    cin >> n >> k;
    long long int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    //Using Prefix Sums
    long long int prefix_sums[n+1];
    prefix_sums[0] = 0;
    for(int i = 1; i < n+1; i++){
        prefix_sums[i] = prefix_sums[i-1] + arr[i-1];
    }
    while(k--){
        long long int a,b;
        cin >> a >> b;
        long long int sum1 = prefix_sums[a-1];
        long long int sum2 = prefix_sums[b];
        long long int sum = sum2 - sum1;
        cout << sum << endl;
    }
}