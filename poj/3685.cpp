#include <iostream>
using namespace std;

long long calc(long long i, long long j){
    return i*i + 100000*i + j*j - 100000*j + i*j;
}

void solve(){
    int n;
    long long m;
    cin >> n >> m;
    long long ok = 1e18, ng = -1e18;
    while(ok-ng > 1){
        long long v = (ok+ng)/2;

        long long count = 0;
        for(int j = 1;j <= n; ++j){
            int ok = 0, ng = n+1;
            while(ng - ok > 1){
                int mid = (ok+ng)/2;
                if(calc(mid, j) <= v){
                    ok = mid;
                }else{
                    ng = mid;
                }
            }
            count += ok;
        }

        if(count >= m){
            ok = v;
        }else{
            ng = v;
        }
    }
    cout << ok << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}