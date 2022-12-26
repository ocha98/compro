#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

struct Person {
    char dir;
    double pos;
    string name;
};

void solve(int n){
    double l, v;
    cin >> l >> v;
    vector<Person> ps(n);
    for(int i = 0;i < n; ++i){
        cin >> ps[i].dir >> ps[i].pos >> ps[i].name;
        ps[i].dir = tolower(ps[i].dir);
    }

    double ans_time = -1;
    double is_positive;
    for(int i = 0;i < n; ++i){
        if(ps[i].dir == 'p'){
            double t = (l - ps[i].pos) / v;
            if(t > ans_time){
                ans_time = t;
                is_positive = true;
            }
        }else{
            double t = ps[i].pos / v;
            if(t > ans_time){
                ans_time = t;
                is_positive = false;
            }
        }
    }

    int cnt_p = 0, cnt_n = 0;
    for(int i = 0;i < n; ++i){
        if(ps[i].dir == 'p'){
            cnt_p++;
        }else{
            cnt_n++;
        }
    }

    int name_i;
    if(is_positive){
        name_i = n - cnt_p;
    }else{
        name_i = cnt_n-1;
    }

    printf("%13.2f %s\n", floor(ans_time*100)/100, ps[name_i].name.c_str());

}

int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n;
    cin >> n;
    while(n != 0){
        solve(n);
        cin >> n;
    }
    return 0;
}
