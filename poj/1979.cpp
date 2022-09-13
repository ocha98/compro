#include <iostream>
#include <string>
#include <queue>
#include <utility>
#include <stdio.h>

using namespace std;

int main(){
    int w, h;
    string s[25];
    bool flag[25][25];
    cin >> w >> h;
    while(!(w == 0 && h == 0)){
        for(int i = 0;i < h; ++i){
            cin >> s[i];
        }

        for(int i = 0;i < 25; ++i){
            for(int j = 0;j < 25; ++j){
                flag[i][j] = false;
            }
        }


        queue< pair<int,int> > que;
        for(int i = 0;i < h; ++i){
            for(int j = 0;j < w; ++j){
                if(s[i][j] == '@'){
                    que.push(pair<int,int>(i, j));
                    flag[i][j] = true;
                    break;
                }
            }
        }


        int count = 1;
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        while(!que.empty()){
            int y = que.front().first;
            int x = que.front().second;
            que.pop();

            for(int i = 0;i < 4; ++i){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx < 0 || nx >= w ||
                   ny < 0 || ny >= h)continue;

                if(s[ny][nx] == '#')continue;
                if(flag[ny][nx])continue;
                count++;
                flag[ny][nx] = true;
                que.push(pair<int,int>(ny, nx));
            }
        }

        cout << count << endl;

        cin >> w >> h;
    }
    return 0;
}