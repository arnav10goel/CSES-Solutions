#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    long long int n;
    cin >> n;
    long long int arr[n-1];
    long long int res[n];
    for(long long int i = 0 ; i < n-1; i++){
        cin >> arr[i];
    }
    for(long long int i = 0; i < n; i++){
        res[i] = i+1;
    }
    sort(arr, arr+n-1);
    long long int i = 0;
    long long int j = 0;
    while(1){
        if(arr[i] != res[j]){
            cout << res[j] << endl;
            break;
        }
        i++;
        j++;
    }

}