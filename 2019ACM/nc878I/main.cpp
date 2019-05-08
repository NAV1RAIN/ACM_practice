#include <bits/stdc++.h>
using namespace std;
struct node {
    int xb, ans, len;
    node(int _xb, int _ans, int _len):xb(_xb),ans(_ans),len(_len){}
};
int n, m;
int q;
int w[205];
vector<int> edge[205];
int jl[205];
int ans[205][205];
queue<node> que;
void bfs(int t) {
    while(!que.empty()) que.pop();
    jl[t] = -1;
    int len = edge[t].size();
    for(int i = 0; i < len; i++) {
        que.push(node(edge[t][i], 0, 1));
    }
    while(!que.empty()) {
        node temp = que.front(); que.pop();
        if(jl[temp.xb] == 0 || jl[temp.xb] == temp.len) {
            jl[temp.xb] = temp.len;
            ans[t][temp.xb] += temp.ans;
        }
        int ll = edge[temp.xb].size();
        for(int i = 0; i < ll; i++) {
            if(jl[edge[temp.xb][i]] == 0) que.push(node(edge[temp.xb][i], temp.ans+w[temp.xb], temp.len+1));
        }
    }
}
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &w[i]);
    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    memset(ans, 0, sizeof(ans));
    for(int i = 1; i <= n; i++) {
        memset(jl, 0, sizeof(jl));
        bfs(i);
    }
    scanf("%d", &q);
    while(q--) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", ans[a][b]+w[a]+w[b]);
    }
    return 0;
}