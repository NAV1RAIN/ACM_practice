#include <bits/stdc++.h>
using namespace std;
int n, m;
int q;
int w[205];
vector<int> edge[205];
int jl[205];
void bfs(int t) {
    jl[t] = -1;
    int len = edge[t].size();

}
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%d", &w[i]);
    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    for(int i = 0; i < n; i++) {
        memset(jl, 0, sizeof(jl));
    }
    return 0;
}