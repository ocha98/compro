#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0;i < n; ++i){
        cin >> a[i];
    }
    int k;
    cin >> k;

    if(k == 1){
        int ans = 0;
        for(int i = 0;i < n; ++i){
            ans = max(ans, a[i]);
        }
        cout << ans << endl;
        return 0;
    }

    int ok = 1e9, ng = 0;
    while(ok - ng > 1){
        int mid = (ok + ng)/2;

        long long count = 0;
        for(int i = 0;i < n; ++i){
            if(a[i] <= mid)continue;
            count += (a[i] - mid + (k-2)) / (k-1);
        }

        if(count <= mid){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    
    cout << ok << endl;

    return 0;
}