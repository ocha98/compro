#include <iostream>
using namespace std;

const int MAX = 1e6;
const long long MOD = 1e9;

int main(){
    int n;
    cin >> n;

    long long dp[MAX+1] = {};
    dp[1] = 1;
    for(int i = 2;i <= n; ++i){
        if(i%2 == 0){
            dp[i] += dp[i/2];
        }

        dp[i] += dp[i-1];
        dp[i] %= MOD;
    }

    cout << dp[n] << endl;
    return 0;
}