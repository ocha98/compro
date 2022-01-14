#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <utility>
using namespace std;

const int INF = 1e9 + 100;

bool compare(pair<double, double> a, pair<double, double> b){
    return a.first < b.second;
}

int solve(int n, int d){
    pair<double,double> p[1005];
    bool ng = false;
    for(int i = 0;i < n; ++i){
        int x, y;
        cin >> x >> y;
        if(y > d)ng = true;
        p[i].first = x - sqrt((double)d*d -y*y);
        p[i].second = x + sqrt((double)d*d -y*y);
    }

    if(ng){
        return -1;
    }

    sort(p, p+n);

    int count = 1;
    double r = INF;
    for(int i = 0;i < n; ++i){
        if(r < p[i].first){
            count++;
            r = p[i].second;
        }else{
            r = min(r, p[i].second);
        }
    }

    return count;
}

int main(){
    int n, d;
    int t = 1;
    cin >> n >> d;
    while(n != 0 || d != 0){
        printf("Case %d: %d\n", t, solve(n, d));
        ++t;
        cin >> n >> d;
    }

    return 0;
}