#include <iostream>
#include <set>
using namespace std;

const int n = 5;
int grid[n][n];
set<int> s;

void dfs(int y, int x, int num, int count){
    if(count == 6){
        s.insert(num);
        return;
    }

    int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
    for(int i = 0;i < 4; ++i){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= n)continue;
        dfs(ny, nx, num*10 + grid[ny][nx],count+1);
    }
}

int main(){
    for(int i = 0;i < n; ++i){
        for(int j = 0;j < n; ++j){
            cin >> grid[i][j];
        }
    }

    for(int i = 0;i < n; ++i){
        for(int j = 0;j < n; ++j){
            dfs(i, j, grid[i][j], 1);
        }
    }

    cout << s.size() << endl;

    return 0;
}