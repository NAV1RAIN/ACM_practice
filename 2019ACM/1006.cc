#include <bits/stdc++.h>
using namespace std;
const int SIZE = 1e5+5;
int a[SIZE], b[SIZE];
int maze1[SIZE][SIZE];
int maze2[SIZE][SIZE];
void Init() {
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(maze1, -1, sizeof(maze1));
    memset(maze2, -1, sizeof(maze2));
}
int main() {
    freopen("RAW/in", "r", stdin);
    freopen("RAW/out", "w", stdout);
    int T;
    scanf("%d", &T);
    while(T--) {
        Init();
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for(int i = 0; i < n; i++) {
            scanf("%d", &b[i]);
        }
        for(int i = 0; i < n - 1; i++) {
            int tx, ty;
            scanf("%d%d", &tx, &ty);
            maze1[0][tx] = a[tx]-b[tx];
            maze1[0][ty] = 
        }
    }
    return 0;
}