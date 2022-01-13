#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

int main(){
    int n, t;
    cin >> n >> t;
    pair<int, int> intv[25000];
    for(int i = 0;i < n; ++i){
        cin >> intv[i].first >> intv[i].second;
    }

    sort(intv, intv + n);

    int count = 0;
    int now = 1;
    int index = 0;
    while(now <= t){
        int max = -1;
        while(index < n && intv[index].first <= now){
            max = std::max(intv[index].second, max);
            index++;
        }
        if(max == -1 || max < now)break;

        now = max + 1;
        count++;
    }


    if(now > t){
        cout << count << endl;
    }else{
        cout << -1 << endl;
    }

    return 0;
}