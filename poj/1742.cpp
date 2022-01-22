#include <iostream>
using namespace std;

const int MAX_N = 100;
const int MAX_M = 100000;

int solve(int n, int m){
    int a[MAX_N], c[MAX_N];
    for(int i = 0;i < n; ++i){
        cin >> a[i];
    }
    for(int i = 0;i < n; ++i){
        cin >> c[i];
    }

    int dp[MAX_M+1] = {};
    for(int i = 0;i <= MAX_M; ++i){
        dp[i] = -1;
    }


    dp[0] = 0;
    for(int i = 0;i < n; ++i){
        for(int j = 0;j <= m; ++j){
            if(dp[j] >= 0){
                dp[j] = c[i];
            }else if(j >= a[i] && dp[j-a[i]] > 0){
                dp[j] = dp[j-a[i]] - 1;
            }else{
                dp[j] = -1;
            }
        }
    }
    int count = 0;
    for(int i = 1;i <= m; ++i){
        if(dp[i] >= 0)count++;
    }
    return count;
}

int main(){
    int n, m;
    cin >> n >> m;
    while(!(n == 0 && m == 0)){
        cout << solve(n, m) << endl;
        cin >> n >> m;
    }
    return 0;
}