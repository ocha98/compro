#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9 + 100;

struct Value{
    int v, id1, id2;
    bool operator<(const Value a) const {
        return v < a.v;
    }
};

void solve(int n){
    vector<int> s(n);
    for(int i = 0;i < n; ++i){
        cin >> s[i];
    }

    vector<Value> sum;
    for(int i = 0;i < n; ++i){
        for(int j = i+1;j < n; ++j){
            Value v;
            v.v = s[i] + s[j];
            v.id1 = i;
            v.id2 = j;
            sum.push_back(v);
        }
    }
    sort(sum.begin(), sum.end());

    typedef vector<Value>::iterator T;
    int ans = -INF;
    for(int i = 0;i < n; ++i){
        for(int j = 0;j < n; ++j){
            if(i == j)continue;
            Value v;
            v.v = s[j] - s[i];
            T start = lower_bound(sum.begin(), sum.end(), v);
            T end = upper_bound(sum.begin(), sum.end(), v);
            for(T itr = start; itr != end; ++itr){
                if(itr->id1 == i || itr->id2 == i ||
                   itr->id1 == j || itr->id2 == j){
                    continue;
                }
                ans = max(s[j], ans);
            }
        }
    }

    if(ans == -INF){
        cout << "no solution" << '\n';
    }else{
        cout << ans << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n;
    cin >> n;
    while(n != 0){
        solve(n);
        cin >> n;
    }
    return 0;
}
