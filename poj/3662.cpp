#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

const int INF = 1e6 + 100;

struct Edge{
    int to, l;
    Edge(){}
    Edge(int to, int l):to(to), l(l){}
};

vector<int> dijkstra(vector<vector<Edge>>& es, int k, int mid){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    vector<int> remk(es.size(), -1);
    remk[0] = k;
    que.push(pair<int, int>(k, 0));
    while(!que.empty()){
        int r = que.top().first;
        int v = que.top().second;
        que.pop();

        if(r < remk[v])continue;

        int m = es[v].size();
        for(int i = 0;i < m; ++i){
            Edge e = es[v][i];
            int nrem = remk[v];
            if(e.l > mid)nrem--;

            if(nrem < 0)continue;

            if(remk[e.to] < nrem){
                remk[e.to] = nrem;
                que.push(pair<int, int>(nrem, e.to));
            }
        }
    }

    return remk;
}

int main(){
    int n, p, k;
    cin >> n >> p >> k;

    vector<vector<Edge>> es(n);
    for(int i = 0;i < p; ++i){
        int a, b, l;
        cin >> a >> b >> l;
        a--; b--;
        es[a].push_back(Edge(b, l));
        es[b].push_back(Edge(a, l));
    }

    int ng = -1, ok = INF;
    while(ok - ng > 1){
        int mid = (ok+ng)/2;

        vector<int> remk = dijkstra(es, k, mid);

        if(remk[n-1] >= 0){
            ok = mid;
        }else{
            ng = mid;
        }
    }

    if(ok == INF){
        cout << -1 << endl;
    }else{
        cout << ok << endl;
    }
}