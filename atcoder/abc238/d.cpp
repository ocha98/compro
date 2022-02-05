#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long a, s;
    cin >> a >> s;

    long long y = s-a;

    if(y < 0){
        cout << "No" << endl;
        return;
    }

    if((y&a) == a){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}

int main(){ 
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}