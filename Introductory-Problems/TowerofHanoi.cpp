#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

//ALGORITHM
// Stacks are 1 (LEFT), 2 (MIDDLE), 3 (RIGHT)
// Move n-1 rods to 2 using 3
// Move largest to 3
// Moving n-1 rods to 3 using 1

int num;
vector<pair<int, int> > moves;

void TowerofHanoi(int n, int from, int to, int mid);

int main(){
    int n;
    cin >> n;
    num = 0;
    TowerofHanoi(n, 1, 3, 2);
    cout << num << endl;
    for(int i = 0; i < moves.size(); i++){
        cout << moves.at(i).first << " " << moves.at(i).second << endl;
    }
}

void TowerofHanoi(int n, int from, int to, int mid){
    if(n == 0){
        return;
    }
    TowerofHanoi(n-1, from, mid, to);
    pair<int, int> local(from, to);
    moves.push_back(local);
    num++;
    TowerofHanoi(n-1, mid, to, from);
}