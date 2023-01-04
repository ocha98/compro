#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

long long abs(long long v){
    if(v < 0){
        return -v;
    }
    return v;
}

void solve(int n){
    vector<long long> a(n);
    for(int i = 0;i < n; ++i){
        cin >> a[i];
    }

    vector<pair<long long, int>> l;
    for(int s = 1;s < 1<<n/2; ++s){
        long long sum = 0;
        int count = 0;
        for(int i = 0;i < n/2; ++i){
            if(s>>i & 1){
                sum += a[i];
                count++;
            }
        }
        l.push_back(make_pair(sum, count));
    }
    vector<pair<long long, int>> r;
    for(int s = 1;s < 1<<(n - n/2); ++s){
        long long sum = 0;
        int count = 0;
        for(int i = 0;i < (n - n/2); ++i){
            if(s>>i & 1){
                sum += a[i+n/2];
                count++;
            }
        }
        r.push_back(make_pair(sum, count));
    }

    pair<long long,int> ans = make_pair((long long)1e18 + 100, 1e9);

    for(int i = 0;i < l.size(); ++i){
        pair<long long, int> tmp = make_pair(abs(l[i].first), l[i].second);
        ans = min(tmp, ans);
    }
    for(int i = 0;i < r.size(); ++i){
        pair<long long, int> tmp = make_pair(abs(r[i].first), r[i].second);
        ans = min(tmp, ans);
    }

    sort(r.begin(), r.end());
    for(int i = 1;i < r.size(); ++i){
        if(r[i].first == r[i-1].first){
            r[i].second = r[i-1].second;
        }
    }
    r.erase(unique(r.begin(), r.end()), r.end());

    for(int i = 0;i < l.size(); ++i){
        vector<pair<long long,int>>::iterator itr =  lower_bound(r.begin(), r.end(), make_pair(-l[i].first, 0));
        for(int k = -1;k <= 0; ++k){
            if(itr+k < r.begin() || itr+k >= r.end())continue;
            long long nsum = abs(l[i].first + (itr+k)->first);
            int ncount = l[i].second + (itr+k)->second;
            pair<long long, int> tmp = make_pair(nsum, ncount);
            ans = min(ans, tmp);
        }
    }

    printf("%lld %d\n", ans.first, ans.second);
}

int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n;
    cin >> n;
    while(n != 0){
        solve(n);
        cin >> n;
    }
    return 0;
}
