#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;

int main(){
    long long int n;
    cin >> n;
    long long int i = 1;
    long long int res = 0;
    while(true){
        long long int a = n;
        long long int temp = a / (int)pow(5,i++);
        res += temp;
        if(temp == 0){
            break;
        }
    }
    cout << res << endl;
}