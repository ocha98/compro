#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 4000;

int main(){
    int n;
    cin >> n;
    int a[MAX_N], b[MAX_N], c[MAX_N], d[MAX_N];
    for(int i = 0;i < n; ++i){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    static int cd[MAX_N*MAX_N];
    for(int i = 0;i < n; ++i){
        for(int j = 0;j < n; ++j){
            cd[i*n + j] = c[i] + d[j];
        }
    }

    sort(cd, cd+n*n);

    long long ans = 0;
    for(int i = 0;i < n; ++i){
        for(int j = 0;j < n; ++j){
            ans += upper_bound(cd, cd+n*n, -(a[i]+b[j])) - lower_bound(cd, cd+n*n, -(a[i]+b[j]));
        }
    }

    cout << ans << endl;

    return 0;
}