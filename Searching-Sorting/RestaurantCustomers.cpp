#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct node{
    int pre;
    int post;
}node;

void recursive_merge(node* arr[], int l, int mid, int r){ //l to mid is one array and mid+1 to r is other --> we have to merge them
    
    //Preparing the 2 arrays for merging
    int size1 = mid-l+1;
    int size2 = r-mid;
    node* l_arr[size1];
    node* r_arr[size2];
    for(int i = 0; i < size1; i++){
        l_arr[i] = arr[i+l];
    }
    for(int i = 0; i < size2; i++){
        r_arr[i] = arr[i+mid+1];
    }

    //Merge
    int i = 0;
    int j = 0;
    int k = l; //we need to take k as l because it is the leftmost index of the array
    while(i < size1 && j < size2){
        if(l_arr[i]->pre <= r_arr[j]->pre){
            arr[k++] = l_arr[i++];
        }
        else if(l_arr[i]->pre > r_arr[j]->pre){
            arr[k++] = r_arr[j++];
        }
    }
    while(i < size1){
        arr[k++] = l_arr[i++];
    }
    while(j < size2){
        arr[k++] = r_arr[j++];
    }
}

void recursive_mergesort(node* arr[], int l, int r){
    if(l >= r){
        return;
    }
    int mid = (l+r)/2;
    //breaking the array into sub components till we get it to one element
    recursive_mergesort(arr, l, mid); //first doing it on the left half of our array
    recursive_mergesort(arr, mid+1, r);

    recursive_merge(arr, l, mid, r);
}

int main(){
    int n;
    cin >> n;
    node* arr[n];
    for(int i = 0; i < n; i++){
        int a,b;
        cin >> a >> b;
        node* temp = (node*)malloc(sizeof(node));
        temp->pre = a;
        temp->post = b;
        arr[i] = temp;
    }
    recursive_mergesort(arr, 0, n-1);
    int max_time = arr[n-1]->post;
    int res[n];
    
}