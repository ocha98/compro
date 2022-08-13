#include <bits/stdc++.h>
using namespace std;

int main(){
  int h1, w1;
  cin >> h1 >> w1;
  vector<vector<int>> a(h1, vector<int>(w1));
  for(int i = 0;i < h1; ++i){
    for(int j = 0;j < w1; ++j){
      cin >> a[i][j];
    }
  }

  int h2, w2;
  cin >> h2 >> w2;
  vector<vector<int>> b(h2, vector<int>(w2));
  for(int i = 0;i < h2; ++i){
    for(int j = 0;j < w2; ++j){
      cin >> b[i][j];
    }
  }

  for(int si = 0;si < (1 << h1); ++si){
    for(int sj = 0;sj < (1 << w1); ++sj){
      vector<vector<int>> dash;
      for(int i = 0;i < h1; ++i){
        vector<int> tmp;
        if((si >> i & 1))continue;
        for(int j = 0;j < w1; ++j){
          if( (sj >> j & 1))continue;
          tmp.push_back(a[i][j]);
        }
        dash.push_back(tmp);
      }
      if(b.size() != dash.size())continue;
      bool ok = true;
      for(int i = 0;i < b.size(); ++i){
        if(dash[i] != b[i]){
          ok = false;
          break;
        }
      }
      if(ok){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  cout << "No" << endl;
  return 0;
}
