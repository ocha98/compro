#include <iostream>
#include <vector>
using namespace std;

int flip(vector<bool> undrink){
    int n = undrink.size();
    int count = 0;
    for(int i = 0;i < n-2; ++i){
        if(!undrink[i])continue;
        count++;
        undrink[i] = !undrink[i];
        undrink[i+1] = !undrink[i+1];
        undrink[i+2] = !undrink[i+2];
    }
    if(undrink[n-2]){
        undrink[n-2] = !undrink[n-2];
        undrink[n-1] = !undrink[n-1];
        count++;
    }

    if(undrink[n-1]){
        return 9999;
    }
    return count;
}

void solve(){
    const int n = 20;
    vector<bool> undrink(n+1);
    for(int i = 1;i <= n; ++i){
        int x;
        cin >> x;
        if(x == 1){
            undrink[i] = true;
        }
    }

    int ans = flip(undrink);
    undrink[0] = true;
    ans = min(ans, flip(undrink));

    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
    return 0;
}
