#include <iostream>
using namespace std;

const int MAX_T = 1000;
const int MAX_A = 100*1000;
const int MOD = 1e6;

int main(){
    int t, a, s, b;
    cin >> t >> a >> s >> b;
    int n[MAX_T] = {};
    for(int i = 0;i < a; ++i){
        int num;
        cin >> num;
        num--;
        n[num]++;
    }
    
    static int dp[MAX_T+1][MAX_A+1] = {};
    for(int i = 0;i <= MAX_T; ++i){
        dp[i][0] = 1;
    }

    for(int i = 0;i < t; ++i){
        for(int j = 1;j <= b; ++j){
            dp[i+1][j] = dp[i+1][j-1] + dp[i][j];
            dp[i+1][j] %= MOD;
            if(j-1-n[i] >= 0){
                dp[i+1][j] -= dp[i][j-1-n[i]];
                dp[i+1][j] = (dp[i+1][j] + MOD)%MOD;
            }
        }
    }

    int sum = 0;
    for(int i = s;i <= b; ++i){
        sum += dp[t][i];
        sum %= MOD;
    }

    cout << sum << endl;

    return 0;
}