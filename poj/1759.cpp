#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    double a;
    cin >> n >> a;

    double ok = 1e9, ng = -1;
    for(int ii = 0;ii < 100; ++ii){
        double mid = (ok+ng)/2;

        vector<double> h(n);
        h[0] = a;
        h[1] = mid;
        for(int i = 2;i < n; ++i){
            h[i] = 2*h[i-1] - h[i-2] + 2;
        }

        bool valid = true;
        for(int i = 0;i < n; ++i){
            if(h[i] < 0)valid = false;
        }

        if(valid){
            ok = mid;
        }else{
            ng = mid;
        }
    }

    vector<double> h(n);
    h[0] = a;
    h[1] = ok;
    for(int i = 2;i < n; ++i){
        h[i] = 2*h[i-1] - h[i-2] + 2;
    }

    printf("%.2f\n", h[n-1]);
    return 0;
}