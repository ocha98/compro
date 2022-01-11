#include <iostream>
#include <functional>
using namespace std;

int w, h;
int sx, sy;
int a[25][25];
int ans = 10000;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool check(int y, int x){
    return 0 <= y && y < h && 0 <= x && x < w;
}

void dfs(int y, int x, int count){
    if(count > 10)return;

    for(int i = 0;i < 4; ++i){
        int nx = x, ny = y;
        nx += dx[i];
        ny += dy[i];
        if(!check(ny, nx))continue;
        if(a[ny][nx] == 1)continue;

        while(check(ny, nx)){
            //goal
            if(a[ny][nx] == 3){
                ans = min(ans, count);
                return;
            }
            //block
            if(a[ny][nx] == 1){
                break;
            }
            nx += dx[i];
            ny += dy[i];
        }

        //drop out
        if(!check(ny, nx)){
            continue;
        }

        a[ny][nx] = 0;
        dfs(ny - dy[i], nx - dx[i], count+1);
        a[ny][nx] = 1;
    }
}

int main(){

    
    cin >> w >> h;
    while(!(w == 0 && h == 0)){
        for(int i = 0;i < h; ++i){
            for(int j = 0;j < w; ++j){
                cin >> a[i][j];
                if(a[i][j] == 2){
                    sy = i;
                    sx = j;
                }
            }
        }


        ans = 10000;
        dfs(sy, sx, 1);
        if(ans == 10000){
            cout << -1 << endl;
        }else{
            cout << ans << endl;
        }

        cin >> w >> h;
    }
    return 0;
}