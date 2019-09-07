#include <stdio.h>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define ll long long
#define ull unsigned long long
#define db double
#define REP(i, lim) for (int i = 0; i < lim; ++i)
#define REPP(i, lim) for (int i = 1; i <= lim; ++i)
#define DEC(i, lim) for (int i = lim; i >= 1; --i)
#define FOR(i, l, r) for (int i = l; i < r; ++i)
#define deBug cout << "===================================" << endl;
#define clr(s) memset(s, 0, sizeof(s))
#define lowclr(s) memset(s, -1, sizeof(s))
const int MAXN = 1000055;
const int inf = 0x3f3f3f3f;
const double eps = 1e-8;
inline int sgn(db x) { return x < -eps ? -1 : x > eps; }
inline db sqr(db x) { return x * x; }

struct P {
    // information
    P() {}
    int num;
    P(db _x, db _y) : x(_x), y(_y) {}
    db x, y;
    // operation
    P operator+(P p) const { return P(x + p.x, y + p.y); }
    P operator-(P p) const { return P(x - p.x, y - p.y); }
    P operator*(db d) const { return P(x * d, y * d); }
    P operator/(db d) const { return P(x / d, y / d); }
    bool operator<(P p) const {
        int c = sgn(x - p.x);
        if (c) return c == -1;
        return sgn(y - p.y) == -1;
    }
    db dot(P p) { return x * p.x + y * p.y; }  // 点积
    db det(P p) { return x * p.y - y * p.x; }  // 叉积

    // other
    P getMid(P p) { return P((x + p.x) / 2, (y + p.y) / 2); }
    P getAno(P m) { return P(m.x - (x - m.x), m.y - (y - m.y)); }
    void input() { scanf("%lf%lf", &x, &y); }
    void print() { printf("(%lf, %lf)\n", x, y); }
    db disTo(P p) { return sqrt(sqr(x - p.x) + sqr(y - p.y)); }
    db abs() { return sqrt(x * x + y * y); }
    db abs2() { return x * x + y * y; }
    db getw() { return atan2(y, x); }
    int getP() const { return sgn(y) == 1 || (sgn(y) == 0 && sgn(x) >= 0); }
} p[1005];

set<P> s;

int main() {
    //    freopen("in.txt", "r", stdin);
    //    freopen("out.txt", "w", stdout);

    int res = inf;
    int n;
    scanf("%d", &n);
    REP(i, n) {
        p[i].input();
        s.insert(p[i]);
    }
    //    sort(p, p+n);
    REP(i, n) {
        int ans = 0;
        P mid = p[0].getMid(p[i]);
        REP(j, n) {
            P tmp = p[j].getAno(mid);
            //            tmp.print();
            if (s.find(tmp) == s.end()) {
                ans++;
            }
        }
        res = min(res, ans);
        //        deBug;
    }

    cout << res << endl;

    return 0;
}
