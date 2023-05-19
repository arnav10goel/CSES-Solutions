#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n,x;
    cin >> n >> x;
    int arr[n];
    int temp[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        temp[i] = arr[i];
    }
    sort(arr, arr + n);
    for(int i = 0; i < n-2; i++){
        int num = arr[i];
        int target = x - num;
        int l = i+1;
        int r = n-1;
        while(l < r){

        }
    }
}