#include <bits/stdc++.h>
using namespace std;
struct Node {
    int x, y;
} dian[10];
int x[10], y[10];
int maze[20][20];
vector<int> xx, yy;
int hh = 0;
void Init() {
    hh = 0;
    xx.clear();
    yy.clear();
    memset(x, 0, sizeof(x));
    memset(y, 0, sizeof(y));
    memset(dian, 0, sizeof(dian));
    memset(maze, 0, sizeof(maze));
}
void dfs(int ) {

}
int main() {
    freopen("RAW/in", "r", stdin);
    freopen("RAW/out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--) {
        Init();
        for (int i = 0; i < 4; i++) {
            scanf("%d%d", &dian[i].x, &dian[i].y);
            xx.push_back(dian[i].x);
            yy.push_back(dian[i].y);
        }
        sort(xx.begin(), xx.end());
        sort(yy.begin(), yy.end());
        int lx = unique(xx.begin(), xx.end()) - xx.begin();
        int ly = unique(yy.begin(), yy.end()) - yy.begin();
        for (int i = 0; i < 4; i++) {
            for (vector<int>::iterator it = xx.begin(); it != xx.end(); it++) {
                if (dian[i].x == *it) {
                    dian[i].x = it - xx.begin() + 1;
                    break;
                }
            }
            for (vector<int>::iterator it = yy.begin(); it != yy.end(); it++) {
                if (dian[i].y == *it) {
                    dian[i].y = it - yy.begin() + 1;
                    break;
                }
            }
        }
        for(int i = 0; i < 4; i++) {
            for(int j = )
        }
    }
    return 0;
}