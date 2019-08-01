#include <queue>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
struct zb {
    int l, r, c;
    zb(int _l, int _r, int _c) : l(_l), r(_r), c(_c){}
    const bool operator == (const zb& a)const{
        if(l == a.l && r == a.r && c == a.c) return true;
        else return false;
    }
};
int ll, rr, cc;
char maze[31][31][31];
int jl[31][31][31];
int fl[10] = {0, 0, 0, 0, -1, 1};
int fr[10] = {-1, 1, 0, 0, 0, 0};
int fc[10] = {0, 0, -1, 1, 0, 0};
int qdl, qdr, qdc, zdl, zdr, zdc;

int bfs() {
    queue<zb> que;
    que.push(zb(qdl, qdr, qdc));
    while(!que.empty()) {
        zb tt = que.front();
        que.pop();
        if(tt.l == zdl && tt.r == zdr && tt.c == zdc) return jl[tt.l][tt.r][tt.c];
        for(int i = 0; i < 6; i++) {
            zb tl(tt.l+fl[i], tt.r+fr[i], tt.c+fc[i]);
            if(tl.l>=0&&tl.l<ll&&tl.r>=0&&tl.r<rr&&tl.c>=0&&tl.c<cc&&jl[tl.l][tl.r][tl.c]==-1&&maze[tl.l][tl.r][tl.c]!='#') {
                que.push(tl);
                jl[tl.l][tl.r][tl.c] = jl[tt.l][tt.r][tt.c]+1;
            }
        }
    }
    return -1;
}
int main() {
    while(scanf("%d%d%d", &ll, &rr, &cc) != EOF) {
        if(!ll && !rr && !cc) break;
        memset(maze, 0, sizeof(maze));
        memset(jl, -1, sizeof(jl));
        for(int i = 0; i < ll; i++) {
            for(int j = 0; j < rr; j++) {
                scanf("%s", maze[i][j]);
                for(int k = 0; k < cc; k++) {
                    if(maze[i][j][k] == 'S') qdl = i, qdr = j, qdc = k;
                    if(maze[i][j][k] == 'E') zdl = i, zdr = j, zdc = k;
                }
            }
        }
        jl[qdl][qdr][qdc] = 0;
        int ans = bfs();
        if(ans == -1) printf("Trapped!\n");
        else printf("Escaped in %d minute(s).\n", ans);
    }
    return 0;
}