#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int to, cost;
};

int main(){ 
    int n, m;
    cin >> n >> m;
    vector<int> h(n);
    for(int i = 0;i < n; ++i){
        cin >> h[i];
    }

    vector<vector<Edge>> to(n);
    for(int i = 0;i < m; ++i){
        int u, v;
        cin >> u >> v;
        u--; v--;
        int cost = h[u] - h[v];

        Edge e;
        e.to = v;
        if(cost < 0){
            e.cost = cost*2;
        }else{
            e.cost = cost;
        }
        to[u].push_back(e);

        e.to = u;
        cost *= -1;
        if(cost < 0){
            e.cost = cost*2;
        }else{
            e.cost = cost;
        }
        to[v].push_back(e);
    }

    vector<long long> hp(n, -1e15-100);
    queue<int> que;
    que.push(0);
    hp[0] = 0;
    while(!que.empty()){
        int v = que.front();
        que.pop();

        for(Edge e : to[v]){
            if(hp[e.to] < hp[v] + e.cost){
                que.push(e.to);
                hp[e.to] = hp[v] + e.cost;
            }
        }
    }

    long long ans = -1;
    for(long long i : hp){
        ans = max(ans, i);
    }

    cout << ans << endl;

    return 0;
}