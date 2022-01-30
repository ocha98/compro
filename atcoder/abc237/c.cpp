#include <bits/stdc++.h>
using namespace std;

int main(){ 
    string s;
    cin >> s;
    int n = s.length();
    int start = -1;
    for(int i = 0;i < n; ++i){
        if(s[i] != 'a'){
            start = i;
            break;
        }
    }
    if(start == -1){
        cout << "Yes" << endl;
        return 0;
    }
    int end = 0;
    for(int i = n-1;i >= 0; --i){
        if(s[i] != 'a'){
            end = i;
            break;
        }
    }

    if( start > (n-1)-end){
        cout << "No" << endl;
        return 0;
    }

    int i = 0;
    while(i <= end-start){
        if(s[start+i] != s[end-i]){
            cout << "No" << endl;
            return 0;
        }
        i++;
    }
    cout << "Yes" << endl;
    return 0;
}