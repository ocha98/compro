#include <iostream>
using namespace std;

const int MAX_T = 1000;
const int MAX_W = 30;

int main(){
    int t, w;
    cin >> t >> w;
    int tree[MAX_T];
    for(int i = 0;i < t; ++i){
        cin >> tree[i];
    }

    int dp[MAX_T+1][MAX_W+1] = {};
    for(int i = 1;i <= t; ++i){
        dp[i][0] = dp[i-1][0];
        if(tree[i-1] == 1){
            dp[i][0]++;
        }
        for(int j = 1;j <= min(w, i); ++j){
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]);
            if((j+1)%2 == tree[i-1]%2){
                dp[i][j]++;
            }
        }
    }

    int ans = -1;
    for(int i = 0;i <= w; ++i){
        ans = max(ans, dp[t][i]);
    }

    cout << ans << endl;

    return 0;
}