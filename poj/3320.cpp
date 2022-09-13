#include <stdio.h>
#include <map>
#include <set>
using namespace std;

const int MAX_P = 1000000;

int main(){
    int p;
    int a[MAX_P];
    set<int> all;
    scanf("%d", &p);
    for(int i = 0;i < p; ++i){
        scanf("%d", &a[i]);
        all.insert(a[i]);
    }

    int n = all.size();
    int r = 0, count = 0;
    int ans = p+1;
    map<int,int> mp;

    for(int l = 0;l < p; ++l){
        while(r < p && count < n){
            if(mp[a[r]] == 0){
                count++;
            }
            mp[a[r]]++;
            r++;
        }
        if(count < n)break;
        ans = min(ans, r-l);
        mp[a[l]]--;
        if(mp[a[l]] == 0){
            count--;
        }
    }

    printf("%d\n", ans);

    return 0;
}