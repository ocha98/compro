#include <bits/stdc++.h>
using namespace std;

int main(){ 
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0;i < n; ++i){
        cin >> a[i];
    }
    
    int p = 0;
    vector<int> cut;
    cut.push_back(p);
    for(int i = 0;i < n; ++i){
        p += a[i];
        p %= 360;
        cut.push_back(p);
    }

    sort(cut.begin(), cut.end());

    int m = cut.size();
    int ans = 360 - cut[m-1];
    for(int i = 1;i < m; ++i){
        ans = max(ans, cut[i] - cut[i-1]);
    }
    cout << ans << endl;
    return 0;
}