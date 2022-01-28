#include <iostream>
using namespace std;

const int MAX_N = 1001;

struct UnionFind{
    int par[MAX_N];
    UnionFind(int n){
        fill(par, par+n, -1);
    }

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

struct Point{
    int x, y;
    int dist_square(Point a){
        return (x-a.x)*(x-a.x) + (y-a.y)*(y-a.y);
    }
};

int main(){
    int n, d;
    cin >> n >> d;
    Point cp[MAX_N];
    for(int i = 0;i < n; ++i){
        cin >> cp[i].x >> cp[i].y;
    }

    UnionFind uf(n);
    bool repaired[MAX_N];
    fill(repaired, repaired + n, false);
    char query;
    while(cin >> query){
        if(query == 'O'){
            int p;
            cin >> p;
            p--;
            for(int i = 0;i < n; ++i){
                if(!repaired[i])continue;
                if(cp[p].dist_square(cp[i]) <= d*d){
                    uf.unite(p, i);
                }
            }
            repaired[p] = true;
        }else{//query == S
            int p, q;
            cin >> p >> q;
            p--; q--;
            if(uf.same(p, q)){
                cout << "SUCCESS" << endl;
            }else{
                cout << "FAIL" << endl;
            }
        }
    }
    return 0;
}