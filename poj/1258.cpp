#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Edge{
    int from, to, cost;
    Edge(){}

    bool operator<(const Edge &a)const{
        return cost < a.cost;
    }
};

struct UnionFind{
    vector<int> par;
    UnionFind(int n):par(n, -1){}

    int root(int x){
        if(par[x] < 0)return x;
        return par[x] = root(par[x]);
    }

    int size(int x) {
        return -par[root(x)];
    }

    void unite(int x, int y){
        x = root(x);
        y = root(y);
        if( x == y)return;

        if (par[x] > par[y]) swap(x,y);
        par[x] += par[y];
        par[y] = x;
    }

    bool same(int x, int y){
        return root(x) == root(y);
    }
};

void solve(int n){
    vector<Edge> es;
    UnionFind uf(n);

    for(int i = 0;i < n; ++i){
        for(int j = 0;j < n; ++j){
            Edge e;
            cin >> e.cost;
            e.from = i;
            e.to = j;
            es.push_back(e);
        }
    }

    sort(es.begin(), es.end());

    long long ans = 0;
    for(int i = 0;i < n*n; ++i){
        if(!uf.same(es[i].from, es[i].to)){
            ans += es[i].cost;
            uf.unite(es[i].from, es[i].to);
        }
    }
    cout << ans << endl;
}


int main(){
    int n;
    while(cin >> n){
        solve(n);
    }
    return 0;
}