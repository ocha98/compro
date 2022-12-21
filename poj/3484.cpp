#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

void solve(vector<long long>& x, vector<long long>& y, vector<long long>& z){
    int n = x.size();
    if(n == 0)return;

    const long long INF = 1e10 + 100;
    long long ok = 0, ng = INF;
    while(ng - ok > 1){
        long long mid = (ok + ng)/2;

        long long count = 0;
        for(int i = 0;i < n; ++i){
            long long limit = min(mid, y[i]);
            if(limit < x[i])continue;
            count += (limit - x[i])/z[i] + 1;
        }

        if(count%2){
            ng = mid;
        }else{
            ok = mid;
        }
    }

    if(ng == INF){
        printf("no corruption\n");
        return;
    }

    int count = 0;
    for(int i = 0;i < n; ++i){
        if(x[i] <= ng && ng <= y[i] && (ng - x[i])%z[i] == 0){
            count++;
        }
    }

    printf("%lld %d\n", ng, count);
}

int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(0);

    string s;
    vector<long long> x, y, z;
    while(getline(cin, s)){
        if(s.size() != 0){
            long long vx, vy, vz;
            istringstream iss(s);
            iss >> vx >> vy >> vz;
            x.push_back(vx);
            y.push_back(vy);
            z.push_back(vz);
        }else{
            solve(x, y, z);
            x.clear();
            y.clear();
            z.clear();
        }
    }
    solve(x, y, z);
    return 0;
}
