#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;

const int MAX_N = 1e5;

struct WeightedUnionFind{
    vector<int> par;
    vector<int> weight;
    WeightedUnionFind(int n):par(n, -1), weight(n,0){}

    void init(){
        fill(par.begin(), par.end(), -1);
        fill(weight.begin(), weight.end(), 0);
    }

    int root(int x){
        if(par[x] < 0){
            return x;
        }
        int r = root(par[x]);
        weight[x] += weight[par[x]];
        return par[x] = r;
    }

    int get_w(int x){
        root(x);
        return weight[x];
    }

    int size(int x) {
        return -par[root(x)];
    }

    int diff(int x, int y){
        return get_w(y) - get_w(x);
    }

    void merge(int x, int y, int w){
        //w[y] - w[x] = w

        w += get_w(x);
        w -= get_w(y);

        x = root(x);
        y = root(y);

        if(x == y)return;

        if(par[x] > par[y]){
            swap(x, y);
            w = -w;
        }

        par[x] += par[y];
        par[y] = x;
        weight[y] = w;
    }

    bool same(int x, int y){
        return root(x) == root(y);
    }
};


int main(){
    int t;
    scanf("%d", &t);

    WeightedUnionFind uf(MAX_N);
    for(int ii = 0;ii < t; ++ii){
        uf.init();

        int n, m;
        scanf("%d%d", &n, &m);

        for(int i = 0;i < m; ++i){
            char query[16];
            int a, b;
            scanf("%s%d%d", query, &a, &b);
            a--; b--;

            if(query[0] == 'A'){
                if(!uf.same(a,b)){
                    printf("Not sure yet.\n");
                }else{
                    if(abs(uf.diff(a,b))%2){
                        printf("In different gangs.\n");
                    }else{
                        printf("In the same gang.\n");
                    }
                }
            }else{// query == D
                uf.merge(a, b, 1);
            }
        }
    }
    return 0;
}