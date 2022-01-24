#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

const int MAX_N = 5000;
const int INF = 1e9 + 100;

int* less_point(int* ng, int* ok, int val){
    ng--; ok--;
    while(ok-ng > 1){
        int* mid = ok + (ng-ok)/2;
        if(*mid <= val){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    return ok;
}

int solve(){
    int n;
    cin >> n;
    pair<int,int> lw[MAX_N];
    for(int i = 0;i < n; ++i){
        int l, w;
        cin >> l >> w;
        lw[i] = pair<int,int>(l, w);
    }

    sort(lw, lw+n);
    int dp[MAX_N+1] = {};
    for(int i = 0;i < n; ++i){
        dp[i] = -1;
    }

    for(int i = 0;i < n; ++i){
        *less_point(dp, dp+n, lw[i].second) = lw[i].second;
    }

    for(int i = 0;i < n; ++i){
        if(dp[i] == -1){
            return i;
        }
    }

    return n;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cout << solve() << endl;
    }
    return 0;
}