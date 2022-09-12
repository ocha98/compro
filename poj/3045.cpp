#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Cow{
    int w, s;
    bool operator< (Cow b){
        return b.w - s < w - b.s;
    }
};

int main(){
    int n;
    cin >> n;
    vector<Cow> ws(n);
    for(int i = 0;i < n; ++i){
        cin >> ws[i].w >> ws[i].s;
    }

    sort(ws.begin(), ws.end());

    int sum = 0;
    int ans = -1e9;
    for(int i = n-1;i >= 0; --i){
        ans = max(ans, sum - ws[i].s);
        sum += ws[i].w;
    }

    cout << ans << endl;

    return 0;
}