#include <iostream>
using namespace std;

const int DAT_SIZE = (1 << 18) - 1;

long long data[DAT_SIZE], datb[DAT_SIZE];

struct SegmentTree{
    int N;
    SegmentTree(int n):N(n){}

    void add(int a, int b, int x){
        add(a, b, x, 0, 0, N);
    }

    void add(int a, int b, int x, int k, int l, int r){
        if(a <= l && r <= b){
            data[k] += x;
        }else if(l < b && a < r){
            datb[k] += (min(b, r) - max(a, l)) * x;
            add(a, b, x, k*2+1, l, (l+r)/2);
            add(a, b ,x, k*2+2, (l+r)/2, r);
        }
    }

    long long sum(int a, int b){
        return sum(a, b, 0, 0, N);
    }

    long long sum(int a, int b, int k, int l, int r){
        if(b <= l || r <= a){
            return 0;
        }

        if(a <= l && r <= b){
            return data[k] * (r - l) + datb[k];
        }else{
            long long res = (min(b, r) - max(a, l)) * data[k];
            res += sum(a, b, k*2+1, l, (l+r)/2);
            res += sum(a, b, k*2+2, (l+r)/2, r);
            return res;
        }
    }
};

int main(){
    int n, q;
    cin >> n >> q;
    SegmentTree seg(n);
    for(int i = 0;i < n; ++i){
        long long a;
        cin >> a;
        seg.add(i, i+1, a);
    }

    for(int i = 0;i < q; ++i){
        char c;
        cin >> c;
        if(c == 'C'){
            int a, b, c;
            cin >> a >> b >> c;
            a--; b--;
            seg.add(a, b+1, c);
        }else{
            int a, b;
            cin >> a >> b;
            a--; b--;
            cout << seg.sum(a, b+1) << endl;
        }
    }

    return 0;
}