#include <iostream>
using namespace std;

const int MAX = 10005;
const long long INF = 1e18 + 100;

int main(){
    int n, s;
    cin >> n >> s;
    int c[MAX], y[MAX];
    for(int i = 0;i < n; ++i){
        cin >> c[i] >> y[i];
    }

    long long ans = 0;
    long long min_cost = INF;
    for(int i = 0;i < n; ++i){
        min_cost = min(min_cost, 1LL*c[i]);
        ans += min_cost * y[i];
        min_cost += s;
    }

    cout << ans << endl;

    return 0;
}