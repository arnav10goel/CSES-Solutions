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
    sort(temp, temp+n);
    int i = 0;
    int j = n-1;
    while(i <= j){
        int sum = temp[i] + temp[j];
        if(sum > x){
            j--;
        }
        if(sum < x){
            i++;
        }
        if(sum == x){
            break;
        }
    }
    if(temp[i] + temp[j] != x){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        int a1 = temp[i];
        int a2 = temp[j];
        int indx = -1;
        int indx2 = -1;
        for(int i = 0; i < n; i++){
            if(arr[i] == a1){
                indx = i;
                break;
            }
        }
        for(int i = 0; i < n; i++){
            if(arr[i] == a2 && i != indx){
                indx2 = i;
                break;
            }
        }
        if(indx == -1 || indx2 == -1){
            cout << "IMPOSSIBLE" << endl;
        }
        else{
            cout << indx+1 << " " << indx2+1 << endl;
        }
        
    }

}