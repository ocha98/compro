#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;

const int MAX = 100;

int main(){
    int n;
    cin >> n;
    int w[MAX];
    for(int i = 0;i < n; ++i){
        cin >> w[i];
    }

    if(n == 1){
        printf("%d.000\n", w[0]);
        return 0;
    }

    sort(w, w+n);
    reverse(w, w+n);
    double old = 2*sqrt(1.0*w[0]*w[1]);
    for(int i = 2;i < n; ++i){
        old = 2*sqrt(w[i]*old);
    }

    printf("%.3f\n", old);

    return 0;
}