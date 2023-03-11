#include<iostream>
#include<vector>

#define mod 1000000007
using namespace std;

int CountingTiles(int n, int m){
    if(n == 1 && m == 2){
        return 1;
    }
    if(n == 2 && m == 1){
        return 1;
    }
    if(n < 1 || m < 1){
        return 0;
    }
    int res1 = CountingTiles(n-1, 2) + CountingTiles(n, m-2);
    int res2 = CountingTiles(n-2, m) + CountingTiles(2, m-1);
    return res1 + res2;
}

int main(){
    int n,m;
    cin >> n >> m;
    cout << CountingTiles(n,m) << endl;
}