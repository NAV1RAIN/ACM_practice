#include <bits/stdc++.h>
using namespace std;
const int SIZE = 2005;
char maze[SIZE][SIZE];
int rN[SIZE], cN[SIZE];
int jrN[SIZE], jcN[SIZE];
struct Node {
    int x, y;
    Node(int _x = 0, int _y = 0) : x(_x), y(_y) {}
} arr[SIZE];
int tol;
int main() {
    freopen("RAW/in", "r", stdin);
    freopen("RAW/out", "w", stdout);
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%s", maze[i]);
        for(int j = 0; j < n; j++) {
            if(maze[i][j] == 'W') {
                rN[i]++, cN[j]++;
                arr[tol++] = Node(j, i);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(rN[i] == n) ans++;
        if(cN[i] == n) ans++;
    }
    if(ans == n + n || k >= n) {
        printf("%d\n", ans);
        return 0;
    }
    printf("%d\n", tol);
    for(int i = 0; i < tol; i++) {
        memset(jcN, 0, sizeof(jcN));
        memset(jrN, 0, sizeof(jrN));
        for(int j = 0; j < n; j++) {
            jcN[j] = cN[j];
            jrN[j] = rN[j];
        }
        int temp = 0;
        for(int j = 0; j < k && j + arr[i].y < n; j++) {
            for(int m = 0; m < k && m + arr[i].x < n; m++) {
                if(maze[j + arr[i].y][m + arr[i].x] == 'B') {
                    jrN[j + arr[i].y]++;
                    jcN[m + arr[i].x]++;
                }
            }
        }
        for(int j = 0; j < n; j++) {
            if(jrN[j] == n) temp++;
            if(jcN[j] == n) temp++;
        }
        if(temp > ans) ans = temp;
        if(ans == n + n) break;
    }
    printf("%d\n", ans);
    return 0;
}