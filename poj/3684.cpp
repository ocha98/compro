#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;

const double g = 10;
const int MAX_N = 100;

int n, h, r, t;
double y[MAX_N];

double calc(int t1){
    //t1:求める時刻
    if(t1 < 0)return h;
    double ts = sqrt(2*h/g);//落下にかかる時間
    int k = (t1/ts);//何回往復するか
    if(k%2 == 0){
        double td = t1 - k*ts;
        return h - g*td*td/2;
    }else{
        double td = (k+1)*ts - t1;
        return h - g*td*td/2;
    }
}

void solve(){    
    cin >> n >> h >> r >> t;
    double ans[MAX_N];
    for(int i = 0;i < n; ++i){
        ans[i] = calc(t-i);
    }
    
    sort(ans, ans+n);
    for(int i = 0;i < n; ++i){
        ans[i] += 2*r*i/100.0;
    }

    printf("%.2f", ans[0]);
    for(int i = 1;i < n; ++i){
        printf(" %.2f", ans[i]);
    }
    printf("\n");
}

int main(){
    int c;
    cin >> c;
    while(c--){
        solve();
    }
    return 0;
}