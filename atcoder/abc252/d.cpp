#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0;i < n; ++i){
    cin >> a[i];
  }

  map<int, int> mp;
  for(int i = 0;i < n; ++i){
    mp[a[i]]++;
  }

  long long ans = n * (n-1) * (n-2)/6;
  for(auto itr = mp.begin(); itr != mp.end(); ++itr){
    long long c = itr->second;
    ans -= c*(c-1)/2 * (n-c);
    ans -= c*(c-1)*(c-2)/6;
  }

  cout << ans << endl;
  return 0;
}