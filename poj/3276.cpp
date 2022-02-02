#include <iostream>
#include <stdio.h>
using namespace std;

const int MAX_N = 5000;
const int INF = 1e9 + 100;

int n;
int cows[MAX_N]; // f:0 b:1

int calc(int k){
    int f[MAX_N] = {}; 
    int count = 0;
    int sum = 0;

    for(int i = 0;i <= n-k; ++i){
        if((cows[i] + sum)%2 == 1){
            count++;
            f[i] = 1;
        }
        sum += f[i];
        if(i-k+1 >= 0){
            sum -= f[i-k+1];
        }


    }

    for(int i = n-k+1;i < n; ++i){
        if((cows[i] + sum)%2 == 1){
            return INF;
        }
        if(i-k+1 >= 0){
            sum -= f[i-k+1];
        }
    }

    return count++;
}

int main(){

    cin >> n;
    for(int i = 0;i < n; ++i){
        char c;
        cin >> c;
        if(c == 'F'){
            cows[i] = 0; 
        }else{
            cows[i] = 1;
        }
    }

    int ans_k = -1;
    int ans_ope = INF;
    for(int i = 1;i <= n; ++i){
        int ope = calc(i);
        if(ope < ans_ope){
            ans_ope = ope;
            ans_k = i;
        }
    }

    printf("%d %d\n", ans_k, ans_ope);

    return 0;
}