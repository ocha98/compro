#include <bits/stdc++.h>
using namespace std;

int main(){
  int l, r;
  cin >> l >> r;
  string s = "atcoder";
  for(int i = l-1;i < r; ++i){
    cout << s[i];
  }

  cout << endl;
  return 0;
}
