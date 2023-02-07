#include<iostream>
#include<vector>
using namespace std;

const long long INF = 1e18 + 100;

struct FordFlukerson {
    struct Edge {
        int to, rev;
        long long cap;
        Edge(int to, long long cap, int rev):to(to), cap(cap), rev(rev){}
    };
    vector<vector<Edge>> es;
    int n;

    FordFlukerson(int n):n(n), es(n){}

    void add_edge(int from, int to, long long cap){
        es[from].push_back(Edge(to, cap, es[to].size()));
        es[to].push_back(Edge(from, 0, es[from].size()-1));
    }

    long long max_flow(int s, int t) {
        long long flow = 0;
        while(true){
            vector<bool> used(n);
            long long f = dfs(s, t, INF, used);
            if(f == 0)return flow;
            flow += f;
        }
    }

    private:
    long long dfs(int v, int t, long long f, vector<bool>& used){
        if(v == t)return f;
        used[v] = true;
        int m = es[v].size();
        for(int i = 0;i < m; ++i){
            Edge& e = es[v][i];
            if(used[e.to])continue;
            if(e.cap <= 0)continue;

            long long d = dfs(e.to, t, min(f, e.cap), used);
            if(d > 0){
                e.cap -= d;
                es[e.to][e.rev].cap += d;
                return d;
            }
        }
        return 0;
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    FordFlukerson ff(2*n+2);
    for(int i = 0;i < k; ++i){
        int r, c;
        cin >> r >> c;
        ff.add_edge(r, c+n, 1);
    }

    for(int i = 1;i <= n; ++i){
        ff.add_edge(0, i, 1);
        ff.add_edge(n+i, 2*n+1, 1);
    }

    cout << ff.max_flow(0, 2*n+1) << endl;
}

int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
}
