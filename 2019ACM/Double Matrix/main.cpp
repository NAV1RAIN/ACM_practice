#include <bits/stdc++.h>
using namespace std;
int a[100][100], b[100][100];
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int temp;
            scanf("%d", &temp);
            if(temp < a[i][j]) {
                b[i][j] = a[i][j];
                a[i][j] = temp;
            } else {
                b[i][j] = temp;
            }
        }
    }
    bool flag = true;
    for(int i = 1; i <= n && flag; i++) {
        for(int j = 1; j <= m && flag; j++) {
            if(a[i][j] <= a[i][j-1] || a[i][j] <= a[i-1][j]) flag = false;
            if(b[i][j] <= b[i][j-1] || b[i][j] <= b[i-1][j]) flag = false;
        }
    }
    if(flag) printf("Possible\n");
    else printf("Impossible\n");
    return 0;
}