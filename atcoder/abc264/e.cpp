#include <bits/stdc++.h>
using namespace std;

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

struct Edge{
  int u, v;
};

int main(){
  int n, m, e;
  cin >> n >> m >> e;

  vector<Edge> uv(e);
  for(int i = 0;i < e; ++i){
    cin >> uv[i].u >> uv[i].v;
    uv[i].u--;
    uv[i].v--;
    uv[i].u = min(uv[i].u, n);
    uv[i].v = min(uv[i].v, n);
  }

  int q;
  cin >> q;
  set<int> stx;
  vector<int> x;

  for(int i = 0;i < q; ++i){
    int val;
    cin >> val;
    x.push_back(val-1);
    stx.insert(val-1);
  }

  UnionFind uf(n+1);

  for(int i = 0;i < e; ++i){
    if(stx.count(i))continue;
    uf.unite(uv[i].u, uv[i].v);
  }

  vector<int> ans;
  for(int i = q-1;i >= 0; --i){
    ans.push_back(uf.size(n) - 1);
    int j = x[i];
    uf.unite(uv[j].u, uv[j].v);
  }

  for(int i = q-1;i >= 0; --i){
    cout << ans[i] << endl;
  }

  return 0;
}
