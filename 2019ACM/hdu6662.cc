#include <bits/stdc++.h>
using namespace std;
const int SIZE = 1e5+5;
int a[SIZE], b[SIZE];

int main() {
    freopen("RAW/in", "r", stdin);
    freopen("RAW/out", "w",stdout);
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for(int i = 0; i < n; i++) {
            scanf("%d", &b[i]);
        }
    }
    return 0;
}