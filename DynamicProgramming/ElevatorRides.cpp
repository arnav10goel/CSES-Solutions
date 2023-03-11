#include<iostream>
#include<vector>

#define mod 1000000007
using namespace std;

int ElevatorRides(long long int arr[], int n, int weight){
    if(n == 0){
        if(arr[n] <= weight){
            return 1;
        }
        else{
            return mod;
        }
    }
    int len = 0;
    // Taken
    if(arr[n] <= weight){
        len = 1 + ElevatorRides(arr, n-1, weight - arr[n]);
    }

    // Not taken
   
    len = min(len, ElevatorRides(arr, n-1, weight));
    return len;
}

int main(){
    long long int n,x;
    cin >> n >> x;
    long long int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    //Function has 2 parameters --> index and weight
    int res = ElevatorRides(arr, n-1, x);
    cout << res << endl;
}