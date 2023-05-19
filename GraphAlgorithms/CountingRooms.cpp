#include<iostream>
#include<vector>

using namespace std;

void dfs(vector<vector<vector<pair<int, int> > > >graph, vector<vector<int> > &visited, int i, int j){
    visited[i][j] = 1;
    vector<pair<int, int> > curr = graph[i][j];
    for(int i = 0; i < curr.size(); i++){
        if(visited[curr[i].first][curr[i].second] != 1){
            dfs(graph, visited, curr[i].first, curr[i].second);
        }
    }
    return;
}

int main(){
    int n, m;
    cin >> n >> m;

    char grid[n][m];
    vector<vector<int> > visited;
    for(int i = 0; i < n; i++){
        vector<int> temp;
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
            temp.push_back(0);
        }
        visited.push_back(temp);
    }

    vector<vector<vector<pair<int, int> > > >graph;

    // Graph Construction
    for(int i = 0; i < n; i++){
        vector<vector<pair<int, int> > > temp1;
        for(int j = 0; j < m; j++){
            vector<pair<int, int> > temp2;
            if(grid[i][j] == '.'){
                if(i-1 >= 0){
                    if(grid[i-1][j] == '.'){
                        temp2.push_back(make_pair(i-1, j));
                    }
                }
                if(i+1 < m){
                    if(grid[i+1][j] == '.'){
                        temp2.push_back(make_pair(i+1, j));
                    }
                }
                if(j-1 >= 0){
                    if(grid[i][j-1] == '.'){
                        temp2.push_back(make_pair(i, j-1));
                    }
                }
                if(j+1 < n){
                    if(grid[i][j+1] == '.'){
                        temp2.push_back(make_pair(i, j+1));
                    }
                }
            }
            temp1.push_back(temp2);
        }
    }

    // Counting
    int counter = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '.' && visited[i][j] != 1){
                counter++;
                dfs(graph, visited, i, j);
            }
        }
    }
    cout << counter << endl;
    
}