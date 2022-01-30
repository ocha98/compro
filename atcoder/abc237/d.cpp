#include <bits/stdc++.h>
using namespace std;

struct LR{
    int num;
    int left = -1, right = -1;
};

int main(){ 
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<LR> v(n+1);
    v[0].num = 0;
    for(int i = 0;i < n; ++i){
        v[i+1].num = i+1;
        if(s[i] == 'L'){
            v[i].left = i+1;
        }else{
            v[i].right = i+1;
        }
    }

    function<void(LR)> dfs = [&](LR x){
        if(x.left != -1)dfs(v[x.left]);
        cout << x.num << " ";
        if(x.right != -1)dfs(v[x.right]);
    };
    dfs(v[0]);
    cout << endl;
    return 0;
}