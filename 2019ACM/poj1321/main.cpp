#include <cstdio>
#include <cstring>
using namespace std;
char maze[10][10];
bool jl[10];
int ans;
int n, k;
void dfs(int r, int num) {
    if(num >= k) {
        ans++;
        return ;
    }
    for(int i = r; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(maze[i][j] == '#' && !jl[j]) {
                jl[j] = true;
                dfs(i+1, num+1);
                jl[j] = false;
            }
        }
    }
    return ;
}
int main() {
    while(~scanf("%d%d", &n, &k)) {
        if(n == -1 && k == -1) break;
        ans = 0;
        memset(jl, 0, sizeof(jl));
//        memset(maze, 0, sizeof(maze));
        for(int i = 0; i < n; i++) {
            scanf("%s", maze[i]);
        }
        dfs(0, 0);
        printf("%d\n", ans);
    }
    return 0;
}