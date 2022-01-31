#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX_M = 20000;

struct Edge{
    int from, to, cost;
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

bool compare(Edge a, Edge b){
    return a.cost > b.cost;
}

int main(){
    int n, m;
    cin >> n >> m;

    Edge es[MAX_M];
    for(int i = 0;i < m; ++i){
        cin >> es[i].from >> es[i].to >> es[i].cost;
        es[i].from--; es[i].to--;
    }

    sort(es, es+m, compare);

    UnionFind uf(n);
    long long ans = 0;
    for(int i = 0;i < m; ++i){
        if(!uf.same(es[i].from, es[i].to)){
            ans += es[i].cost;
            uf.unite(es[i].from, es[i].to);
        }
    }


    if(uf.size(0) == n){
        cout << ans << endl;
    }else{
        cout << -1 << endl;
    }

    return 0;
}