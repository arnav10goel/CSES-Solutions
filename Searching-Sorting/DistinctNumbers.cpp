#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int main(){
    long long int n;
    cin >> n;
    long long int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);
    long long int count = 1;
    for(int i = 0; i < n-1; i++){
        if(arr[i] != arr[i+1]){
            count += 1;
        }
    }
    cout << count << endl;

}
