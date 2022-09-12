#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

struct Jewel{
    int v, w;
};

int main(){
    int n, k;
    cin >> n >> k;
    vector<Jewel> j(n);
    for(int i = 0;i < n; ++i){
        cin >> j[i].v >> j[i].w;
    }

    vector<double> jj(n);
    double ok = 0, ng = 1e8;
    for(int ii = 0;ii < 50; ++ii){
        double mid = (ok+ng)/2;

        for(int i = 0;i < n; ++i){
            jj[i] = j[i].v - mid*j[i].w;
        }
        sort(jj.begin(), jj.end());
        double sum = 0;
        for(int i = n-1;i >= n-k; --i){
            sum += jj[i];
        }

        if(sum >= 0){
            ok = mid;
        }else{
            ng = mid;
        }
    }

    vector<pair<double,int>> p(n);
    for(int i = 0;i < n; ++i){
        p[i].first  = j[i].v - ok*j[i].w;
        p[i].second = i+1;
    }
    sort(p.begin(), p.end());

    cout << p[n-1].second;
    for(int i = n-2;i  >= n-k; --i){  
        cout << " " << p[i].second;
    }
    cout << endl;
    
}