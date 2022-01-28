#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

const int MAX_C = 2500;
const int MAX_L = 2500;

bool compare(pair<int,int> a, pair<int,int> b){
    if(a.second == b.second){
        return a.first < a.second;
    }
    return a.second < b.second;
}

bool in_range(pair<int,int> cow, pair<int,int> sunscreen){
    return cow.first <= sunscreen.first && sunscreen.first <= cow.second;
}

int main(){
    int c, l;
    cin >> c >> l;
    pair<int,int> cows[MAX_C];
    for(int i = 0;i < c; ++i){
        int min, max;
        cin >> min >> max;
        cows[i] = pair<int,int>(min, max);
    }

    pair<int,int> sunscreen[MAX_L];
    for(int i = 0;i < l; ++i){
        int spf, cover;
        cin >> spf >> cover;
        sunscreen[i] = pair<int,int>(spf, cover);
    }

    sort(cows, cows+c, compare);
    sort(sunscreen, sunscreen+l);

    int ans = 0;
    for(int i = 0;i < c; ++i){
        for(int j = 0;j < l; ++j){
            if(sunscreen[j].second == 0)continue;
            if(in_range(cows[i], sunscreen[j])){
                ans++;
                sunscreen[j].second--;
                break;
            }
        }
    }

    cout << ans << endl;

    return 0;
}