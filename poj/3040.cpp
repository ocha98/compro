#include <iostream>
#include <stdio.h>
#include <utility>
#include <algorithm>
using namespace std;

const int MAX = 20;

int main(){
    int n, c;
    cin >> n >> c;
    pair<int,int> vb[MAX];
    for(int i = 0;i < n; ++i){
        int v, b;
        cin >> v >> b;
        vb[i] = pair<int,int>(v, b);
    }

    sort(vb, vb+n);

    long long ans = 0;
    int m = 0;
    for(int i = n-1;i >= 0; --i){
        if(vb[i].first > c){
            ans += vb[i].second;
        }else{
            m = i+1;
            break;
        }
    }


    while(true){
        int count[MAX] = {};
        int total = 0;
        for(int i = m-1;i >= 0; --i){
            int num = min(vb[i].second, (c-total)/vb[i].first);
            count[i] = num;
            total += num * vb[i].first;
        }

        if(total < c){
            for(int i = 0;i < m; ++i){
                if(vb[i].second > count[i]){
                    total += vb[i].first;
                    count[i]++;
                    break;
                }
            }
        }

        if(total < c)break;

        int week = 1e9 + 100;
        for(int i = 0;i < m; ++i){
            if(count[i] == 0)continue;
            week = min(week, vb[i].second/count[i]);
        }
        for(int i = 0;i < m; ++i){
            vb[i].second -= count[i]*week;
        }

        ans += week;
    }

    cout << ans << endl;

    return 0;
}