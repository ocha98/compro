#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_M = 1000;

struct Interval{
    int start, end, eff;
    Interval(){}
    Interval(int start, int end, int eff):start(start), end(end), eff(eff){}

    bool operator < (const Interval &a) const {
        return end < a.end;
    }
};

int main(){
    int n, m, r;
    cin >> n >> m >> r;
    Interval intv[MAX_M];
    for(int i = 0;i < m; ++i){
        cin >> intv[i].start >> intv[i].end >> intv[i].eff;
        intv[i].end += r;
    }

    sort(intv, intv+m);
    int dp[MAX_M+1] = {};// i番目未満で選んだ時の最大値
    for(int i = 0;i < m;++i){
        dp[i+1] = max(dp[i], intv[i].eff);
        for(int j = 0;j < i; ++j){
            if(intv[j].end <= intv[i].start){
                dp[i+1] = max(dp[i+1], dp[j+1] + intv[i].eff);
            }
        }
    }

    cout << dp[m] << endl;
    return 0;
}