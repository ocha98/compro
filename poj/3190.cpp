#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

const int MAX = 50000 + 5;

struct Cow{
    int start, end, id;
};

struct Stall{
    int room, end;
    Stall(int room, int end):room(room), end(end){}

    bool operator > (const Stall& s) const{
        return end > s.end; 
    }
};

bool compare_cow(Cow a, Cow b){
    return a.start < b.start;
}

int main(){
    int n;
    cin >> n;
    Cow c[MAX];
    for(int i = 0;i < n; ++i){
        cin >> c[i].start >> c[i].end;
        c[i].id = i;
    }



    int ans[MAX];
    int num = 1;
    sort(c, c+n, compare_cow);
    priority_queue<Stall, vector<Stall>, greater<Stall> > que;
    que.push(Stall(1, c[0].end));
    ans[c[0].id] = 1;
    for(int i = 1;i < n; ++i){
        int room;
        if(c[i].start <= que.top().end){
            room = que.size()+1;
            num++;
        }else{
            room = que.top().room;
            que.pop();
        }
        que.push(Stall(room, c[i].end));
        ans[c[i].id] = room;
    }

    cout << num << endl;
    for(int i = 0;i < n; ++i){
        cout << ans[i] << endl;
    }

    return 0;
}