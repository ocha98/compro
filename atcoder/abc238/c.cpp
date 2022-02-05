#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

long long sum(long long n){
    n %= MOD;
    return (n*(n+1)/2)%MOD;
}

int main(){ 
    long long n;
    cin >> n;
    long long pow10 = 1;
    long long ans = 0;
    while(pow10*10-1 <= n){
        ans += sum(pow10*10 - pow10);
        ans %= MOD;
        pow10 *= 10;
    }

    ans +=  sum(max(0LL,n - pow10 + 1));
    ans %= MOD;
    cout << ans << endl;

    return 0;
}