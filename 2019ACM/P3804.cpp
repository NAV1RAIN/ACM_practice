#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL LNF = 0x3f3f3f3f3f3f3f3f;
const int CHAR = 26;
const int MAXN = 1e6+5;
struct SAM_Node {
    SAM_Node *fa, *next[CHAR];
    int len;
    LL cnt;
    void clear() {
        fa = 0;
        memset(next, 0, sizeof(next));
        cnt = 0;
    }
} pool[MAXN*2];
SAM_Node *root, *tail;
SAM_Node* newnode (int len) {
    SAM_Node* cur = tail++;
    cur->clear();
    cur->len = len;
    return cur;
}
void SAM_init() {
    tail = pool;
    root = newnode(0);
}
SAM_Node* extend(SAM_Node* last, int x) {
    SAM_Node *p = last, *np = newnode(p->len+1);
    while(p && !p->next[x]) {
        p->next[x] = np, p = p->fa;
    }
    if(!p) np->fa = root;
    else {
        SAM_Node* q = p->next[x];
        if(q->len == p->len + 1) np->fa = q;
        else {
            SAM_Node* nq = newnode(p->len + 1);
            memcpy(nq->next, q->next, sizeof(q->next));
            nq->fa = q->fa;
            q->fa = np->fa = nq;
            while(p && p->next[x] == q) {
                p->next[x] = nq, p = p->fa;
            }
        }
    }
    return np;
}
char str[MAXN];
struct Edge {
    int to, next;
} edge[MAXN*2];
int head[MAXN], tot;
void addedge(int u, int v) {
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}
SAM_Node *end[MAXN];
int topcnt[MAXN]; //拓扑排序使用
SAM_Node *topsam[MAXN*2];

int main() {
    freopen("RAW/in", "r", stdin);
    freopen("RAW/out", "w", stdout);
    scanf("%s", str);
    int len = strlen(str);
    end[0] = root;
    for(int i = 0; i < len; i++) {
        if(end[i+1] != 0) continue;
        end[i + 1] = extend(end[i], str[i + 1] - 'a');
    }
    SAM_init();
    return 0;
}
