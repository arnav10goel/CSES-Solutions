#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    long long int n,k;
    cin >> n >> k;
    long long int arr[n];
    for(long long int i = 0; i < n; i++){
        arr[i] = i+1;
    }

    long long int count = 0;
    long long int temp = 0;
    long long int i = -1;
    while(count != n){
        i = (i+1) % n;
        if(arr[i] != -1){
            temp += 1;
        }
        if(arr[i] != -1 && temp == k+1){
            cout << arr[i] << " ";
            count += 1;
            temp = 0;
            arr[i] = -1;
        }
    }
}