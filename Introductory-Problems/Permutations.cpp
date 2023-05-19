#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    // Logic 1
    if(n == 1){
        cout << 1 << endl;
    }
    else if(n == 2 || n == 3){
        cout << "NO SOLUTION" << endl;
    }
    // else if(n == 4){
    //     cout << "2 4 1 3" << endl;
    // }
    // else{
    //     int arr[n];
    //     for(int i = 1; i <= n; i++){
    //         arr[i-1] = i;
    //     }
    //     vector<int> res;
    //     int i = 0;
    //     int j = n-1;
    //     while(i <= j){
    //         res.push_back(arr[i]);
    //         res.push_back(arr[j]);
    //         i++;
    //         j--;
    //     }
    //     swap(res[0], res[n-1]);
    //     for(int i = 0; i < n; i++){
    //         cout << res[i] << " ";
    //     }
    // }
    // Logic 2: Append all evens starting from 2, then append all odds starting from 1
    vector<int> res;
    for(int i = 2; i <= n; i = i+2){
        res.push_back(i);
    }
    for(int i = 1; i <= n; i = i + 2){
        res.push_back(i);
    }
    for(int i = 0; i < n; i++){
        cout << res[i] << " ";
    }
}