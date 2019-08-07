#include <bits/stdc++.h>
using namespace std;
const int SIZE = 1e5+5;
const int INF = 0x3f3f3f3f;
struct Node {
    int a, b;
    int id;
    double aDb;
    Node() : a(0), b(0) {}
} arr[SIZE];
int xNum, num;
bool cmp(const Node& a, const Node& b) {
    if(a.aDb != b.aDb) return a.aDb < b.aDb;
    else return a.id < b.id;
}
struct A {
    int a, b;
    int gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b); }
    void get() {
        int num = gcd(a, b);
        a /= num;
        b /= num;
    }
    inline bool operator < (const A &tt) const {
        double t1 = (double)a/b;
        double t2 = (double)tt.a/tt.b;
        return t1 < t2;
    }
};
set<A> ans;
double l, r;
int main() {
    // freopen("RAW/in", "r", stdin);
    // freopen("RAW/out", "w", stdout);
    int T;
    scanf("%d", &T);
    while(T--) {
        ans.clear();
        l = r = -INF;
        int n, c;
        xNum = num = 0;
        scanf("%d%d", &n, &c);
        for(int i = 0; i < n; i++) {
            scanf("%d%d", &arr[i].a, &arr[i].b);
            arr[i].id = i;
            xNum += (-arr[i].a);
            num += (-arr[i].b);
            arr[i].aDb = -((double)arr[i].b/arr[i].a);
        }
        sort(arr, arr + n, cmp);
        bool flag = false;
        for(int i = 0; i <= n; i++) {
            if(i < n) r = arr[i].aDb;
            else r = INF;
            int a = c-num;
            if(xNum == 0 && a == 0) {
                flag = true;
                break;
            }
            A temp;
            if(a == 0) {
                temp.a = 0;
                temp.b = 1;
                if(0 >= l && 0 <= r) ans.insert(temp); 
            } else {
                double tt = (double)a/xNum;
                if(tt >= l && tt <= r) {
                    temp.a = a;
                    temp.b = xNum;
                    temp.get();
                    ans.insert(temp);
                }
            }
            num += 2*arr[i].b;
            xNum += 2*arr[i].a;
            l = arr[i].aDb;
        }
        if(flag) printf("-1");
        else {
            int len = ans.size();
            printf("%d", len);
            for(set<A>::iterator it = ans.begin(); it != ans.end(); it++) {
                if(1.0*(*it).a/(*it).b < 0) printf(" -");
                else printf(" ");
                printf("%d/%d", abs((*it).a), abs((*it).b));
            }
        }
        printf("\n");
    }
    return 0;
}