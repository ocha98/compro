#include <iostream>
using namespace std;

const int MAX_N = 15;
const int MAX_M = 15;
const int INF = 1e8;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int m, n;
int tile[MAX_M][MAX_N];
int flip[MAX_M][MAX_N];
int ans[MAX_M][MAX_N];

int get_color(int i, int j){
    int sum = flip[i][j] + tile[i][j];
    for(int d = 0;d < 4; ++ d){
        int ni = i+dy[d], nj = j+dx[d];
        if(0 <= ni && ni < m && 0 <= nj && nj < n){
            sum += flip[ni][nj];
        }
    }
    return sum%2;
}

int calc(){
    int count = 0;
    for(int i = 0;i < m-1; ++i){
        for(int j = 0;j < n; ++j){
            if(get_color(i, j) == 1){
                flip[i+1][j] = 1;
                count++;
            }
        }
    }

    for(int i = 0;i < n; ++i){
        if(get_color(m-1, i) == 1){
            return INF;
        }
    }
    return count;
}

int main(){
    cin >> m >> n;

    for(int i = 0;i < m; ++i){
        for(int j = 0;j < n; ++j){
            cin >> tile[i][j];
        }
    }

    int min_ope = INF;
    for(int i = 0;i < (1<<n); ++i){
        fill(flip[0], flip[m], 0);
        int count = 0;
        for(int j = 0;j < n; ++j){
            if((i >> j & 1) == 1){
                flip[0][j] = 1;
                count++;
            }
        }

        int retu = calc();
        if(retu+count < min_ope){
            min_ope = retu+count;
            for(int i = 0;i < m; ++i){
                for(int j = 0;j < n; ++j){
                    ans[i][j] = flip[i][j];
                }
            }
        }
    }


    if(min_ope == INF){
        cout << "IMPOSSIBLE" << endl;
    }else{
        for(int i = 0;i < m; ++i){
            cout << ans[i][0];
            for(int j = 1;j < n; ++j){
                cout << " " << ans[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}