#include <bits/stdc++.h>
using namespace std;

int main(){
  const string g = "atcoder";
  string s;
  cin >> s;

  int ans = 1e9 + 100;
  set<string> st;
  queue<pair<int, string>> que;
  que.push({0, s});
  while(que.size()){
    int count = que.front().first;
    string t = que.front().second;
    que.pop();
    if(t == g){
      cout << count << endl;
      return 0;
    }
    for(int i = 0;i < g.length()-1; ++i){
      string cp = t;
      swap(cp[i], cp[i+1]);
      if(st.count(cp))continue;
      st.insert(cp);
      que.push({count+1, cp});
    }
  }

  return 0;
}
