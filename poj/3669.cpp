#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

const int INF = 1e9 + 100;
const int MAX = 305;

struct Point{
    int y, x;
    Point(int y, int x):y(y),x(x){}
};


int main(){
    int des[MAX][MAX];
    int time[MAX][MAX];
    for(int i = 0;i < MAX; ++i){
        for(int j = 0;j < MAX; ++j){
            des[i][j] = INF;
            time[i][j] = INF;
        }
    }

    int m;
    cin >> m;
    for(int i = 0;i < m; ++i){
        int t, x, y;
        cin >> x >> y >> t;

        des[y][x]   = min(t, des[y][x]);
        des[y+1][x] = min(t, des[y+1][x]);
        des[y][x+1] = min(t, des[y][x+1]);
        if(y-1 >= 0)des[y-1][x] = min(t, des[y-1][x]);
        if(x-1 >= 0)des[y][x-1] = min(t, des[y][x-1]);
    }

    
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    queue<Point> que;

    time[0][0] = 0;
    que.push(Point(0, 0));
    while(!que.empty()){
        Point p = que.front();
        que.pop();

        if(des[p.y][p.x] == INF){
            cout << time[p.y][p.x] << endl;
            return 0;
        }

        if(time[p.y][p.x] >= des[p.y][p.x]){
            continue;
        }
        
        for(int i = 0;i < 4; ++i){
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];
            if(nx < 0 || ny < 0)continue;
            if(time[ny][nx] != INF)continue;

            time[ny][nx] = time[p.y][p.x] + 1;
            que.push(Point(ny, nx));   
        }
    }

    cout << -1 << endl;

    return 0;
}