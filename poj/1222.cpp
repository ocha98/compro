#include <iostream>
#include <vector>
using namespace std;

const int H = 5;
const int W = 6;

void solve(vector<vector<bool>>& board, int num){
    int di[] = {0, 0, 1, -1};
    int dj[] = {1, -1, 0, 0};
    for(int s = 0;s < (1<< W); ++s){
        vector<vector<bool>> pushed(H, vector<bool>(W));
        vector<vector<bool>> flipped(H, vector<bool>(W));

        for(int j = 0;j < W; ++j){
            if((s>>j & 1) == 0)continue;
            pushed[0][j] = true;
            flipped[0][j] = !flipped[0][j];
            for(int d = 0;d < 4; ++d){
                int ni = 0 + di[d];
                int nj = j + dj[d];

                if(ni < 0 || nj < 0 || ni >= H || nj >= W)continue;

                flipped[ni][nj] = !flipped[ni][nj];
            }
        }

        for(int i = 1;i < H; ++i){
            for(int j = 0;j < W; ++j){
                if(flipped[i-1][j] == board[i-1][j])continue;

                pushed[i][j] = true;
                flipped[i][j] = !flipped[i][j];
                for(int d = 0;d < 4; ++d){
                    int ni = i + di[d];
                    int nj = j + dj[d];

                    if(ni < 0 || nj < 0 || ni >= H || nj >= W)continue;

                    flipped[ni][nj] = !flipped[ni][nj];
                }
            }
        }

        bool ok = true;
        for(int j = 0;j < W; ++j){
            if(flipped[H-1][j] != board[H-1][j]) ok = false;
        }

        if(!ok) continue;

        cout << "PUZZLE #" << num << '\n';
        for(int i = 0;i < H; ++i){
            cout << pushed[i][0] ? 1 : 0;
            for(int j = 1;j < W; ++j){
                cout << " " << pushed[i][j] ? 1 : 0;
            }
            cout << '\n';
        }
        return;
    }
}

int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(0);
    vector<vector<bool>> board(5, vector<bool>(6));
    int n;
    cin >> n;
    for(int ii = 1;ii <= n; ++ii){
        for(int i = 0;i < H; ++i){
            for(int j  = 0;j < W; ++j){
                int x;
                cin >> x;
                board[i][j] = x ? true : false;
            }
        }
        solve(board, ii);
    }
    return 0;
}
