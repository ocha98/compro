#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

const int INF = 1e9 + 100;
const int MAX_N = 300;

int main(){
    int n, m;
    scanf("%d%d", &n, &m);

    vector<vector<int> > to(n);
    for(int i = 0;i < m; ++i){
        int k;
        scanf("%d", &k);
        vector<int> cow;
        for(int j = 0;j < k; ++j){
            int num;
            scanf("%d", &num);
            num--;
            cow.push_back(num);
        }
        for(int j = 0;j < k; ++j){
            for(int l = j+1;l < k; ++l){
                to[cow[j]].push_back(cow[l]);
                to[cow[l]].push_back(cow[j]);
            }
        }
    }

    int ans = INF;
    for(int i = 0;i < n; ++i){
        int sum = 0;
        queue<int> que;
        int dist[MAX_N];
        fill(dist, dist+n, INF);

        dist[i] = 0;
        que.push(i);
        while(!que.empty()){
            int v = que.front();
            que.pop();
            int d = to[v].size();
            for(int j = 0;j < d; ++j){
                int x = to[v][j];
                if(dist[x] > dist[v]+1){
                    dist[x] = dist[v]+1;
                    sum += dist[x];
                    que.push(x);
                }
            }
        }
        ans = min(sum, ans);
    }

    ans = (ans*1.0)/(n-1) * 100;
    printf("%d\n", ans);
    return 0;
}