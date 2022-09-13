#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        vector<int> a(n);
        for(int i = 0;i < n; ++i){
            scanf("%d", &a[i]);
        }

        sort(a.begin(), a.end());

        long long med = 1LL*n*(n-1)/4+1;

        int ng = 1e9+10, ok = 0;
        while(ng - ok > 1){
            int mid = (ok+ng)/2;

            long long count = 0;
            for(int i = 0;i < n; ++i){
                count += a.end() - lower_bound(a.begin()+i+1, a.end(), a[i]+mid);
            }

            if(count >= med){
                ok = mid;
            }else{
                ng = mid;
            }
        }

        printf("%d\n", ok);
    }
    return 0;
}