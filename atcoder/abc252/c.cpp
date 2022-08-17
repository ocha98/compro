#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<string> s(n);
  for(int i = 0;i < n; ++i){
    cin >> s[i];
  }

  int ans = 1e9 + 100;
  for(int i = 0;i < 10; ++i){
    int max = 0;
    set<int> st;
    for(int j = 0;j < n; ++j){
      int x = s[j].find('0'+i);
      while(st.count(x)){
        x += 10;
      }
      st.insert(x);
      max = std::max(x, max);
    }
    ans = min(max, ans);
  }
  

  cout << ans << endl;
  return 0;
}
