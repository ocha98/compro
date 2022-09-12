#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(int n, int k){
    vector<long long> a(n), b(n);
    for(int i = 0;i < n; ++i){
        cin >> a[i];
    }
    for(int i = 0;i < n; ++i){
        cin >> b[i];
    }

    double ng = 1e18, ok = 0;
    for(int i = 0;i < 100; ++i){
        double mid = (ok + ng)/2;

        vector<double> s(n);
        for(int i = 0;i < n; ++i){
            s[i] = 100*a[i] - mid*b[i];
        }
        sort(s.begin(), s.end());
        double sum = 0;
        for(int i = n-1;i >= k; --i){
            sum += s[i];
        }

        if(sum >= 0){
            ok = mid;
        }else{
            ng = mid;
        }
    }

    printf("%.0f\n", ok);
}

int main(){
    int n, k;
    cin >> n >> k;
    while(!(n == 0 && k == 0)){
        solve(n, k);
        cin >> n >> k;
    }

    return 0;
}