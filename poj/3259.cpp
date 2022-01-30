#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MAX_N = 500;
const int INF = 1e9 + 100;

struct Edge{
    int from, to, cost;
    Edge(){}
    Edge(int from , int to, int cost):from(from), to(to), cost(cost){}
};

bool find_negative_loop(int V, vector<Edge> es){
    int n = es.size();
    vector<int> dist(n);
    for(int i = 0;i < V; ++i){
        for(int j = 0;j < n; ++j){
            Edge e = es[j];
            if(dist[e.to] > dist[e.from] + e.cost){
                dist[e.to] = dist[e.from] + e.cost;
                if(i == V-1)return true;
            }
        }
    }
    return false;
}

string solve(){
    int n, m, w;
    cin >> n >> m >> w;
    vector<Edge> es;

    for(int i = 0;i < m; ++i){
        int s, e, t;
        cin >> s >> e >> t;
        s--; e--;
        es.push_back(Edge(s, e, t));
        es.push_back(Edge(e, s, t));
    }

    for(int i = 0;i < w; ++i){
        Edge e;
        cin >> e.from >> e.to >> e.cost;
        e.from--; e.to--;
        e.cost *= -1;
        es.push_back(e);
    }

    if(find_negative_loop(n, es)){
        return "YES";
    }else{
        return "NO";
    }
}

int main(){
    int f;
    cin >> f;
    while(f--){
        cout << solve() << endl;
    }
    return 0;
}