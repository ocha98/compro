#include <iostream>
#include <vector>
#include <utility>
using namespace std;

void solve(){
    long long n;
    cin >> n;
    long long l = 1, r = 1;
    long long sum = 0;
    vector<pair<long long, long long>> ans;
    while(l*l <= n){
        if(sum == n){
            ans.push_back(make_pair(l ,r));
        }
        if(r*r <= n && sum < n){
            sum += r*r;
            r++;
        }else{
            sum -= l*l;
            l++;
        }
    }

    cout << ans.size() << '\n';
    for(int i = 0;i < ans.size(); ++i){
        cout << ans[i].second - ans[i].first;
        for(int k = ans[i].first;k < ans[i].second; ++k){
            cout << " " << k;
        }
        cout << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
    return 0;
}
