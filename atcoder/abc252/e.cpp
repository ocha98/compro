#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18 + 100;

struct Edge{
  int to, cost, id;
  Edge(int to, int cost, int id):to(to), cost(cost), id(id){}
};

int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<Edge>> es(n);
  for(int i = 0;i < m; ++i){
    int a, b, c;
    cin >> a >> b >> c;
    a--;b--;
    es[a].push_back(Edge(b, c, i+1));
    es[b].push_back(Edge(a, c, i+1));
  }

  const long long INF = 1e18 + 100;
  vector<long long> dist(n, INF);
  vector<int> from(n, -1);
  priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> que;

  dist[0] = 0;
  que.push({0, 0});
  while(!que.empty()){
    long long d = que.top().first;
    int v = que.top().second;
    que.pop();

    if(dist[v] != d)continue;

    for(Edge e : es[v]){
      if(dist[e.to] <= d + e.cost)continue;
      dist[e.to] = d + e.cost;
      from[e.to] = e.id;
      que.push({dist[e.to], e.to});
    }
  }

  for(int i = 1;i < n; ++i){
    cout << from[i] << endl;
  }
  
  return 0;
}
