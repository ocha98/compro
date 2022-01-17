#include <iostream>
using namespace std;

const int MAX = 350;

int main(){
    int n;
    cin >> n;
    int p[MAX][MAX];
    for(int i = 0;i < n; ++i){
        for(int j = 0;j <= i; ++j){
            cin >> p[i][j];
        }
    }

    int dp[MAX+1][MAX+1] = {};
    dp[0][1] = p[0][0];
    for(int i = 1;i < n; ++i){
        for(int j = 1;j <= i+1; ++j){
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + p[i][j-1];
        }
    }

    int ans = -1;
    for(int i = 1;i <= n; ++i){
        ans = max(ans, dp[n-1][i]);
    }
    
    cout << ans << endl;

    return 0;
}