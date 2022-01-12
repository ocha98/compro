#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 13;
int dp[MAX][MAX];//pascal's triangle

int sum(int nums[], int n){
    int retu = 0;
    for(int i = 1;i <= n; ++i){
        retu += dp[n][i] * nums[i];
    }
    return retu;
}

int main(){
    int n, total;
    cin >> n >> total;

    dp[1][1] = 1;
    for(int i = 2;i < MAX; ++i){
        for(int j = 1;j <= i; ++j){
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }

    int nums[MAX];
    for(int i = 1;i <= n; ++i){
        nums[i] = i;
    }

    do{
        if(sum(nums, n) == total){
            cout << nums[1];
            for(int i = 2;i <= n; ++i){
                cout << " " << nums[i];
            }
            cout << endl;
            return 0;
        }
    }while(next_permutation(nums+1, nums+1 + n));

    return 0;
}