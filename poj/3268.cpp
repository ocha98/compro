#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9+100;

struct Edge{
    int to, cost;
    Edge(){}
    Edge(int to, int cost):to(to), cost(cost){}
};

vector<int> dijkstra(int start, vector<vector<Edge> >& es){
    int n = es.size();
    vector<int> dist(n, INF);
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > que;
    dist[start] = 0;
    que.push(pair<int,int>(0, start));
    while(!que.empty()){
        int w = que.top().first;
        int v = que.top().second;
        que.pop();

        if(dist[v] < w)continue;

        int m = es[v].size();
        for(int i = 0;i < m; ++i){
            Edge e = es[v][i];
            if(dist[e.to] > dist[v] + e.cost){
                dist[e.to] = dist[v] + e.cost;
                que.push(pair<int,int>(dist[e.to], e.to));
            }
        }
    }
    return dist;
}

int main(){
    int n, m, x;
    cin >> n >> m >> x;
    x--;
    vector<vector<Edge> > g1(n);
    vector<vector<Edge> > g2(n);
    for(int i = 0;i < m; ++i){
        int a, b, t;
        cin >> a >> b >> t;
        a--; b--;
        g1[a].push_back(Edge(b, t));
        g2[b].push_back(Edge(a, t));
    }

    vector<int> dist1 = dijkstra(x, g1);
    vector<int> dist2 = dijkstra(x, g2);

    int ans = -1;
    for(int i = 0;i < n; ++i){
        ans = max(ans, dist1[i] + dist2[i]);
    }

    cout << ans << endl;
    return 0;
}