#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long int k;
        cin >> k;
        long long int k_val = 0;
        int i = 0;
        while(k_val <= k){
            i++;
            k_val += (i*pow(10, i-1)*9);
        }
        long long int prev_k_val = k_val - ((i*pow(10, i-1)*9));
        long long int k_leftover = k - prev_k_val;
        long long int base = pow(10,i-1);
        long long int end = pow(10,i);
        long long int target = k_leftover/i;
        long long int remainder = k_leftover % i;
        long long int mid = (base+end)/2;
        if(remainder == 0){
            while(base < end-1){
                mid = (base+end)/2;
                if((mid-base+1) > target){
                    end = mid;
                }
                else if((mid-base+1) < target){
                    base = mid;
                }
                else{
                    break;
                }
            }
            cout << mid % 10 << endl;
        }
        else{
            while(base < end-1){
                mid = (base + end)/2;
                if((mid-base) > target+1){
                    end = mid;
                }
                else if((mid-base+1) < target+1){
                    base = mid;
                }
                else{
                    break;
                }
            }
            int res = mid+1;
        }

    }
}