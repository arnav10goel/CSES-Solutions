#include<iostream>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;

int main(){
    string s;
    cin >> s;
    int arr[26];
    for(int i = 0; i < 26; i++){
        arr[i] = 0;
    }
    for(int i = 0; i < s.length(); i++){
        arr[s[i]-'A'] += 1;
    }
    int num_odds = 0;
    for(int i = 0; i < 26; i++){
        if(arr[i] % 2 == 1){
            num_odds += 1;
        }
    }
    if(s.length()%2 == 0){
        if(num_odds > 0){
            cout << "NO SOLUTION" << endl;
            return 0;
        }
    }
    if(s.length() % 2 != 0){
        if(num_odds > 1){
            cout << "NO SOLUTION" << endl;
            return 0;
        }
    }
    char res[s.length()];
    int l = 0;
    int r = s.length()-1;
    for(int i = 0; i < 26; i++){
        if(arr[i] != 0 && arr[i] % 2 == 0){
            while(arr[i] != 0){
                res[l++] = 'A' + i;
                res[r--] = 'A' + i;
                arr[i] = arr[i] - 2;
            }
        }
    }
    for(int i = 0; i < 26; i++){
        if(arr[i] != 0 && arr[i] % 2 != 0){
            while(arr[i] != 0){
                res[l++] = 'A'+i;
                arr[i] = arr[i] - 1;
            }
        }
    }
    for(int i = 0; i < s.length(); i++){
        cout << res[i];
    }
    cout << endl;
}