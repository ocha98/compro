#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0;i < n; ++i){
        cin >> a[i];
    }

    int ok = 1e9 + 100, ng = 0;
    while(ok - ng > 1){
        int mid = (ok+ng)/2;

        int count = 1;
        int sum = 0;
        for(int i = 0;i < n; ++i){
            if(a[i] > mid){
                count = 1e9;
                break;
            }

            sum += a[i];
            if(sum > mid){
                count++;
                sum = a[i];
            }
        }

        if(count <= m){
            ok = mid;
        }else{
            ng = mid;
        }
    }

    cout << ok << endl;

    return 0;
}