#include <bits/stdc++.h>
using namespace std;
const int SIZE = 1e6 + 5;

char y[SIZE];
int l[SIZE], r[SIZE];
int tol = 0;
int tor = 0;
int main() {
    // freopen("RAW/in", "r", stdin);
    // freopen("RAW/out", "w", stdout);
    scanf("%s", y);
    int n = strlen(y);
    int jl = 0;
    for (int i = 0; i < n; i++) {
        if (y[i] == 'o') {
            if (jl > 1) {
                l[tol] = jl - 1;
            } else {
                l[tol] = 0;
            }
            if (tol >= 1) l[tol] += l[tol - 1];
            tol++;
            jl = 0;
        } else {
            jl++;
        }
    }
    jl = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (y[i] == 'o') {
            if (jl > 1) {
                r[tor] = jl - 1;
            } else {
                r[tor] = 0;
            }
            if (tor >= 1) r[tor] += r[tor - 1];
            tor++;
            jl = 0;
        } else {
            jl++;
        }
    }
    long long ans = 0;
    for(int i = 0; i < tol; i++) {
        ans += ((long long)l[i])*((long long)r[tol-i-1]);
    }
    printf("%lld\n", ans);
    return 0;
}