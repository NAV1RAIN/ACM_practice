#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL LNF = 0x3f3f3f3f3f3f3f3f;
const int CHAR = 26;
const int MAXN = 1e6 + 5;
struct SAM_Node {
    SAM_Node *fa, *next[CHAR];
    int len;
    LL cnt;
    void clear() {
        fa = 0;
        memset(next, 0, sizeof(next));
        cnt = 0;
    }
} pool[MAXN * 2];
SAM_Node *root, *tail;
SAM_Node* newnode(int len) {
    SAM_Node* cur = tail++;
    cur->clear();
    cur->len = len;
    return cur;
}
void SAM_init() {
    tail = pool;
    root = newnode(0);
}
SAM_Node* EXEND(SAM_Node* last, int x) {
    SAM_Node *p = last;
    SAM_Node *np = newnode(p->len + 1);
    while (p && !p->next[x]) {
        p->next[x] = np, p = p->fa;
    }
    if (!p)
        np->fa = root;
    else {
        SAM_Node* q = p->next[x];
        if (q->len == p->len + 1)
            np->fa = q;
        else {
            SAM_Node* nq = newnode(p->len + 1);
            memcpy(nq->next, q->next, sizeof(q->next));
            nq->fa = q->fa;
            q->fa = np->fa = nq;
            while (p && p->next[x] == q) {
                p->next[x] = nq, p = p->fa;
            }
        }
    }
    return np;
}
char str[MAXN];
struct Edge {
    int to, next;
} edge[MAXN * 2];
int head[MAXN], tot;
void addedge(int u, int v) {
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}
SAM_Node *END[MAXN];
int topcnt[MAXN];  //拓扑排序使用
SAM_Node* topsam[MAXN * 2];

int main() {
    freopen("RAW/in", "r", stdin);
    freopen("RAW/out", "w", stdout);
    scanf("%s", str + 1);
    int len = strlen(str + 1);
    SAM_init();
    memset(END, 0, sizeof(END));
    END[0] = root;
    for (int i = 0; i < len; i++) {
        if (END[i + 1] != 0) continue;
        END[i + 1] = EXEND(END[i], str[i + 1] - 'a');
    }
    memset(topcnt, 0, sizeof(topcnt));
    int num = tail - pool;
    for(int i = 0; i < num; i++) topcnt[pool[i].len]++;
    for(int i = 1; i <= len; i++) topcnt[i] += topcnt[i - 1];
    for(int i = 0; i < num; i++) topsam[--topcnt[pool[i].len]] = &pool[i];
    long long ans = 0;
    for(int i = num - 1; i >= 0; i--) {
        SAM_Node *p = topsam[i];
        p->cnt = 1;
        printf("%c", )
        for(int i = 0; i < 26; i++) {
            if(p->next[i]) {
                printf("%c", i + 'a');
                p->cnt += p->next[i]->cnt;
            }
        }
        printf("\n");
    }
    printf("%lld\n", (root)->cnt);
    return 0;
}
