#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  set<int> b;
  for(int& i : a)cin >> i;
  for(int i = 0;i < k; ++i){
    int x;
    cin >> x;
    x--;
    b.insert(x);
  }

  int max = -1;
  for(int i = 0;i < n; ++i){
    if(a[i] > max)max = a[i];
  }

  bool yes = false;
  for(int i = 0;i < n; ++i){
    if(a[i] != max)continue;
    if(b.count(i)){
      yes = true;
    }
  }

  if(yes){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }

  return 0;
}
