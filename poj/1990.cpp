#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

template<typename T>
struct FenwickTree{
    int n;
    vector<T> data;

    FenwickTree(int n):n(n), data(n+1){}

    void add(int i, T x){
        while(i <= n){
            data[i] += x;
            i += i & -i;
        }
    }

    T sum(int i) const{
        T retu_sum = 0;
        while(i > 0){
            retu_sum += data[i];
            i -= i & -i;
        }

        return retu_sum;
    }

    T sum(int l, int r) const {
        return sum(r) - sum(l);
    }
};

struct Cow {
    int v, x;
    bool operator<(const Cow& a)const {
        return v < a.v;
    }
};

void solve(){
    int n;
    cin >> n;
    vector<Cow> cs(n);
    for(int i = 0;i < n; ++i){
        cin >> cs[i].v >> cs[i].x;
    }

    sort(cs.begin(), cs.end());

    const int X_MAX = 20000;
    FenwickTree<long long> dist(X_MAX+1);
    FenwickTree<long long> cnt(X_MAX+1);
    long long ans = 0;
    for(int i = 0;i < n; ++i){
        ans += (cnt.sum(cs[i].x)*cs[i].x - dist.sum(cs[i].x))*cs[i].v;

        ans += (dist.sum(cs[i].x, X_MAX) - cnt.sum(cs[i].x, X_MAX)*cs[i].x)*cs[i].v;

        dist.add(cs[i].x, cs[i].x);
        cnt.add(cs[i].x, 1);
    }

    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
    return 0;
}
