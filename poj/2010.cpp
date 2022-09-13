#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

const int MAX_C = 100000;

struct Cow{
    int aid, csat;
};

bool comp_csat(Cow a, Cow b){
    return a.csat < b.csat;
}

int main(){
    int n, c, f;
    cin >> n >> c >> f;
    Cow cows[MAX_C];
    for(int i = 0;i < c; ++i){
        cin >> cows[i].csat >> cows[i].aid;
    }

    sort(cows, cows+c, comp_csat);

    long long lower[MAX_C], upper[MAX_C];
    priority_queue<int> que;
    long long total = 0;
    for(int i = 0;i < c; ++i){
        lower[i] = total;
        if(que.size() == n/2){
            if(cows[i].aid < que.top()){
                total -= que.top();
                que.pop();
                que.push(cows[i].aid);
                total += cows[i].aid;
            }
        }else{
            que.push(cows[i].aid);
            total += cows[i].aid;
        }
    }

    total = 0;
    que = priority_queue<int>();
    for(int i = c-1;i >= 0; --i){
        upper[i] = total;
        if(que.size() == n/2){
            if(cows[i].aid < que.top()){
                total -= que.top();
                que.pop();
                que.push(cows[i].aid);
                total += cows[i].aid;
            }
        }else{
            que.push(cows[i].aid);
            total += cows[i].aid;
        }
    }

    long long min_aid = f;
    long long median = -1;
    for(int i = n/2;i < (c-n/2); ++i){
        if(lower[i] + upper[i] + cows[i].aid <= min_aid){
            median = cows[i].csat;
        }
    }

    cout << median << endl;

    return 0;
}