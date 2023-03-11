#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int BinarySearch(int arr[], int l, int r, int x){
    int low = l;
    int high = r;
    int mid;
    mid = (low + high)/2;
    if(x < arr[low]){
        return -1;
    }
    if(x > arr[high]){
        return -1;
    }
    if(arr[mid] == x){
        return mid;
    }
    else if(arr[mid] > x){
        return BinarySearch(arr, low, mid-1, x);
    }
    else if(arr[mid] < x){
        return BinarySearch(arr, mid+1, high, x);
    }
    else{
        return -1;
    }
}

int main(){
    int n,m;
    scanf("%d %d", &n, &m);
    int ticket_prices[n];
    for(int i=0; i<n; i++){
        scanf("%d", &ticket_prices[i]);
    }
    int max_customer_price[m];
    for(int i=0; i<m; i++){
        scanf("%d", &max_customer_price[i]);
    }
    sort(ticket_prices, ticket_prices+n);
    int soln_indexes[m];
    for(int i = 0; i < m; i++){
        int flag = -1;
        for(int j = max_customer_price[i]; j > 0 ; j--){
            flag = BinarySearch(ticket_prices, 0, n-1, j);
            if(flag != -1){
                break;
            }
        }
        soln_indexes[i] = flag;
    }
    for(int i = 0; i < m; i++){
        if(soln_indexes[i] == -1){
            printf("-1\n");
        }
        else{
            int a = soln_indexes[i];
            for(int j = 0; j < m; j++){
                if(j > i && soln_indexes[j] == a){
                    soln_indexes[j] = -1;
                }
            }
            printf("%i\n", ticket_prices[a]);
        }
    }
}