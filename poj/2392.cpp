#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_K = 400;
const int MAX_A = 40000;

struct Block{
    int h, a, c;
    Block(){}
    Block(int h, int a, int c):h(h), a(a), c(c){}

    bool operator <(const Block &r) const{
        return a < r.a;
    }
};

int main(){
    int k;
    cin >> k;
    Block blocks[MAX_K];
    for(int i = 0;i < k; ++i){
        int h, a, c;
        cin >> h >> a >> c;
        blocks[i] = Block(h, a, c);
    }

    sort(blocks, blocks+k);

    int dp[MAX_A+1];
    fill(dp, dp+MAX_A+1, -1);
    dp[0] = 0;
    for(int i = 0;i < k; ++i){
        for(int j = 0;j <= blocks[i].a; ++j){
            if(dp[j] >= 0){
                dp[j] = blocks[i].c;
            }else if(j >= blocks[i].h && dp[j-blocks[i].h] > 0){
                dp[j] = dp[j-blocks[i].h]-1;
            }else{
                dp[j] = -1;
            }
        }
    }

    int ans = 0;
    for(int i = 0;i <= MAX_A; ++i){
        if(dp[i] >= 0){
            ans = i;
        }
    }

    cout << ans << endl;
    return 0;
}