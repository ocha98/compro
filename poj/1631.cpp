#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 40000;
const int INF = 1e9 + 100;

void solve(){
    int n;
    cin >> n;
    int p[MAX_N];
    for(int i = 0;i < n; ++i){
        cin >> p[i];
    }

    int dp[MAX_N+1] = {};
    fill(dp, dp+n, INF);
    for(int i = 0;i < n; ++i){
        *lower_bound(dp, dp+n, p[i]) = p[i];
    }

    cout << (lower_bound(dp, dp+n, INF) - dp) << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}