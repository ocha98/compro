#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int l, n, m;
    cin >> l >> n >> m;
    vector<int> d(n);
    for(int i = 0;i < n; ++i){
        cin >> d[i];
    }

    sort(d.begin(), d.end());

    int ok = 0, ng = 1e9 + 10;
    while(ng - ok > 1){
        int mid = (ok + ng)/2;

        int old = 0;
        int count = 0;
        for(int i = 0;i < n; ++i){
            if(d[i] - old < mid){
                count++;
            }else{
                old = d[i];
            }
        }
        if(l - old < mid)count++;

        if(count <= m){
            ok = mid;
        }else{
            ng = mid;
        }
    }

    cout << ok << endl;

    return 0;
}