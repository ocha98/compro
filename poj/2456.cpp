#include <algorithm>
#include <iostream>
using namespace std;

const int MAX_N = 1e6;
const int INF = 1e9 + 100;

int n, m;
int x[MAX_N];

bool judge(int d){
    int last = 0;
    for(int i = 1;i < m; ++i){
        int point = last+1;
        while(point < n && x[point] - x[last] < d){
            point++;
        }
        if(point == n)return false;
        last = point;
    }
    return true;
}

int main(){
    cin >> n >> m;
    for(int i = 0;i < n; ++i){
        cin >> x[i];
    }

    sort(x, x+n);

    int ok = 0, ng = INF;
    while(ng - ok > 1){
        int mid = (ok + ng) / 2;
        if(judge(mid)){
            ok = mid;
        }else{
            ng = mid;
        }
    }

    cout << ok << endl;

    return 0;
}