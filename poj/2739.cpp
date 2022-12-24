#include <iostream>
#include <vector>
using namespace std;

const int MAX = 10000;

void solve(){
    vector<bool> is_prime(MAX+1, true);
    is_prime[0] = is_prime[1] = false;

    for(int i = 2;i <= MAX; ++i){
        if(!is_prime[i])continue;
        for(int k = 2*i;k <= MAX; k += i){
            is_prime[k] = false;
        }
    }

    vector<int> primes;
    for(int i = 2;i <= MAX; ++i){
        if(is_prime[i]){
            primes.push_back(i);
        }
    }
    int m = primes.size();


    int x;
    cin >> x;
    while(x != 0){
        int l = 0, r = 0;
        int sum = 0;
        int ans = 0;
        while(l < m){
            if(sum == x){
                ans++;
            }
            if(r < m && sum < x){
                sum += primes[r];
                r++;
            }else{
                sum -= primes[l];
                l++;
            }
        }

        cout << ans << '\n';

        cin >> x;
    }
}

int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(0);
    solve();
    return 0;
}
