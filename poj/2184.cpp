#include <iostream>
using namespace std;

const int MAX_N = 100;
const int OFFSET = 100000;
const int MAX_RANGE = 200000;
const int INF = 1e9+100;

int main(){
    int n;
    cin >> n;
    int s[MAX_N], f[MAX_N];
    for(int i = 0;i < n; ++i){
        cin >> s[i] >> f[i];
    }

    static int dp[2][MAX_RANGE+1];
    fill(dp[0], dp[2], -INF);

    dp[0][OFFSET] = 0;
    for(int i = 0;i < n; ++i){
        for(int j = 0;j <= MAX_RANGE; ++j){
            int now = i%2, next = (i+1)%2;
            if(dp[now][j] == -INF)continue;
            dp[next][j] = max(dp[next][j], dp[now][j]);
            dp[next][j+f[i]] = max(dp[next][j+f[i]], dp[now][j] + s[i]);
        }
    }

    int ans = 0;
    for(int i = OFFSET;i <= MAX_RANGE; ++i){
        if(dp[n%2][i] < 0)continue;
        ans = max(ans, dp[n%2][i] + i - OFFSET);
    }
    cout << ans << endl;
    return 0;
}