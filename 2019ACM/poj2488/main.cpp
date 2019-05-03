#include <cstdio>
#include <cstring>
using namespace std;

int p, q;
int fr[10] = {-1,1,-2,2,-2,2,-1,1};
int fc[10] = {-2,-2,-1,-1,1,1,2,2};
bool maze[100][100];
bool flag;
int hr[100];
char hc[100];
void dfs(int r, int c, int num) {
    maze[r][c] = true;
    hr[num] = 1+r, hc[num] = 'A'+c;
    if(num == p*q) {
        flag = true;
        return ;
    }
    for(int i = 0; i < 8; i++) {
        int nr = r+fr[i], nc = c+fc[i];
        if(nr >= 0 && nr < p && nc >= 0 && nc < q && !maze[nr][nc] && !flag) {
            dfs(nr, nc, num+1);
            if(!flag) maze[nr][nc] = false;
        }
    }
}
int main() {
//    freopen("in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for(int time = 1; time <= n; time++) {
        memset(maze, false, sizeof(maze));
        flag = false;
        scanf("%d%d", &p, &q);
        dfs(0, 0, 1);
        printf("Scenario #%d:\n", time);
        if(flag) {
            for(int i = 1; i <= p*q; i++) {
                printf("%c%d", hc[i], hr[i]);
            }
            printf("\n");
        } else {
            printf("impossible\n");
        }
        if(time != n) printf("\n");
    }
    return 0;
}