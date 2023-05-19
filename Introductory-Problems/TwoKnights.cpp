#include<iostream>

using namespace std;

int main(){
    long long int n;
    cin >> n;
    for(long long int i = 1; i <= n; i++){
        long long int total_comb = (i*i)*((i*i)-1)/2;
        long long int two_three = 2*(i-1)*(i-2);
        long long int three_two = 2*(i-1)*(i-2);
        long long int total_attacked = two_three + three_two;
        long long int res = total_comb - total_attacked;
        cout << res <<  endl;
    }
}