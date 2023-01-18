#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        arr[i] = i+1;
    }

    int count = 0;
    int temp = 0;
    int i = -1;
    while(count != n){
        i = (i+1) % n;
        if(arr[i] != -1){
            temp += 1;
        }
        if(arr[i] != -1 && temp == 2){
            cout << arr[i] << " ";
            count += 1;
            temp = 0;
            arr[i] = -1;
        }
    }
}