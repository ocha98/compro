#include <iostream>
#include <stdio.h>
#include <functional>
#include <cmath>
using namespace std;

const int MAX_N = 10000;
const int INF = 1e9 + 100;

int n, k;
double a[MAX_N];

bool judge(double x){
    int count = 0;
    for(int i = 0;i < n; ++i){
        count += (int)(a[i]/x);
    }
    return count >= k;
}

int main(){
    cin >> n >> k;
    for(int i = 0;i < n; ++i){
        cin >> a[i];
    }


    double ok = 0, ng = INF;
    for(int i = 0;i < 100; ++i){
        double mid = (ok+ng)/2;

        if(judge(mid)){
            ok = mid;
        }else{
            ng = mid;
        }
    }

    printf("%.2f\n", floor(ok*100)/100);

    return 0;
}