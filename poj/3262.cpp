#include <iostream>
#include <utility>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int MAX = 100000;

bool compare(pair<int,int> a, pair<int,int> b){
    return a.first*b.second < a.second*b.first;
}

int main(){
    int n;
    cin >> n;
    pair<int,int> td[MAX];
    for(int i = 0;i < n; ++i){
        int t, d;
        cin >> t >> d;
        td[i] = pair<int,int>(t, d);
    }

    sort(td, td+n, compare);

    long long ans = 0;
    long long time = 0;
    for(int i = 0;i < n; ++i){
        ans += time * td[i].second;
        time += td[i].first*2;
    }
    
    cout << ans << endl;

    return 0;
}