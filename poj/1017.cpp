#include <iostream>
#include <stdio.h>
using namespace std;

const int N = 6;

int solve(int p[]){
    int ans = 0;
    
    ans += p[6];

    ans += p[5];
    p[1] = max(0, p[1]-11*p[5]);

    ans += p[4];
    p[2] -= 5*p[4];
    if(p[2] < 0){
        p[1] += p[2]*5;
    }
    p[2] = max(0, p[2]);
    p[1] = max(0, p[1]);

    ans += (p[3] + 3)/4;
    int rem = (4 - p[3]%4)%4;
    if(rem > 0)p[2] = max(0, p[2] - (1 + 2*(rem-1)));
    p[1] = max(0, p[1]-rem*5);


    ans += (p[2] + 8)/9;
    rem = (9 - p[2]%9)%9;
    p[1] = max(0, p[1] - rem*4);

    ans += (p[1] + 35)/36;

    return ans;
}

int main(){
    while(true){
        bool end = true;
        int p[N+1];
        for(int i = 1;i <= N; ++i){
            cin >> p[i];
            if(p[i] != 0)end = false;
        }

        if(end)break;

        cout << solve(p) << endl;
    }

    return 0;
}