#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


int main(){
    string s;
    cin >> s;
    int res = -1;
    int count = 1;
    for(int i = 0; i < s.length()-1; i++){
        if(s[i] == s[i+1]){
            count += 1;
        }
        if(s[i] != s[i+1]){
            res = max(count, res);
            count = 1;
        }
    }
    cout << max(res,count) << endl;
}