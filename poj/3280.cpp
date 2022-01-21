#include <iostream>
#include <map>
#include <string>
using namespace std;

const int INF = 1e9 + 100;
const int MAX_M = 2000;

int main(){
    int n, m;
    string s;
    cin >> n >> m;
    cin >> s;
    map<char, int> mp;
    for(int i = 0;i < n; ++i){
        char c;
        int add, del;
        cin >> c >> add >> del;
        mp[c] = min(add, del);
    }

    static int dp[MAX_M+1][MAX_M+1];
    for(int i = 0;i <= m; ++i){
        for(int j = 0;j <= m; ++j){
            dp[i][j] = INF;
        }
    }

    //len 0 and len 1
    for(int i = 0;i < m; ++i){
        dp[i][i] = dp[i][i+1] = 0;
    }

    for(int len = 2;len <= m; ++len){
        for(int i = 0;i <= m-len; ++i){
            int j = i+len;//[i, j)
            if(s[i] == s[j-1]){
                dp[i][j] = dp[i+1][j-1];
            }
            dp[i][j] = min(dp[i][j-1] + mp[s[j-1]], dp[i][j]);
            dp[i][j] = min(dp[i+1][j] + mp[s[i]], dp[i][j]);
        }
    }

    cout << dp[0][m] << endl;
    return 0;
}