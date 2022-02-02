#include <iostream>
using namespace std;

const int MAX_N = 100000;

void solve(){
    int n, s;
    int a[MAX_N];
    cin >> n >> s;
    for(int i = 0;i < n; ++i){
        cin >> a[i];
    }

    int r = 0, sum = 0;
    int ans = n+1;
    for(int l = 0;l < n; ++l){
        while(r < n && sum < s){
            sum += a[r];
            r++;
        }
        if(sum < s)break;
        ans = min(ans, r-l);
        sum -= a[l];
    }
    if(ans == n+1){
        cout << 0 << endl;
    }else{
        cout << ans << endl;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}