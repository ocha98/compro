#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <stdio.h>
using namespace std;

int solve(){
    string num;
    string str, s;
    getline(cin, str);
    stringstream ss(str);
    while (getline(ss, s, ' ')){
        num += s;
    }

    // ==sol==
    int n = num.length();
    int mid = n/2;
    int ans = 1e9 + 100;

    sort(num.begin(), num.end());

    do{
        if(mid > 1 && num[0] == '0')continue;
        if(n-mid > 1 && num[mid] == '0')continue;

        int num1 = 0, num2 = 0;
        for(int i = 0;i < mid; ++i){
            num1 *= 10;
            num1 += num[i]-'0';
        }
        for(int i = mid;i < n; ++i){
            num2 *= 10;
            num2 += num[i]-'0';
        }

        ans = min(ans, abs(num1 - num2));
    }while(next_permutation(num.begin(), num.end()));

    return ans;
}

int main(){
    int t;
    string s;
    cin >> t;
    getline(cin, s);
    while(t--){
        cout << solve() << endl;
    }
    return 0;
}