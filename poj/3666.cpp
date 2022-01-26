#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 2000;
const int INF = 1e9+100;

int solve(int n, int a[]){
    int h[MAX_N];
    for(int i = 0;i < n; ++i){
        h[i] = a[i];
    }

    sort(h, h+n);

    static int dp[MAX_N+1][MAX_N+1];
    fill(dp[0], dp[0]+n, 0);

    for(int i = 0;i < n; ++i){
        int cost = INF;
        for(int j = 0;j < n; ++j){
            cost = min(cost, dp[i][j]);
            dp[i+1][j] = cost + abs(a[i] - h[j]);
        }   
    }

    int retu = INF;
    for(int i = 0;i < n; ++i){
        retu = min(retu, dp[n][i]);
    }
    return retu;
}

int main(){
    int n;
    cin >> n;
    int a[MAX_N];
    for(int i = 0;i < n; ++i){
        cin >> a[i];
    }

    int ans = INF;
    ans = min(ans, solve(n, a));
    for(int i = 0;i < n; ++i){
        a[i] *= -1;
    }
    ans = min(ans, solve(n, a));

    cout << ans << endl;
    return 0;
}