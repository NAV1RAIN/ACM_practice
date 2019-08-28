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
const int CHARSET_SIZE = 26;  // 字符集大小为常数

struct SuffixAutomaton {
    struct Node {
        Node *ch[CHARSET_SIZE], *next;
        int max, posCnt;  // posCnt 表示其 end-pos 集合的大小

        // 对于一个新的节点，如果它表示了一个新的后缀，则它的 end-pos 集合中多一个位置
        // 否则它的 end-pos 集合仅仅是前缀树上所有子节点的 end-pos 集合的并
        Node(int max = 0, bool newSuffix = false) : ch(), next(NULL), max(max), posCnt(newSuffix) {}
    } * start, *last, _pool[MAXN * 2 + 1], *_curr;
    // 为了方便枚举所有节点，我们将节点放在内存池中，_curr 指向当前最后一个节点之后

    vector<Node *> topo;  // 存储拓扑序（按照 max 从小到大排序）

    void init() {
        _curr = _pool;
        start = last = new (_curr++) Node;
    }

    Node *extend(int c) {
        // 节点 u 表示了一个新的后缀
        Node *u = new (_curr++) Node(last->max + 1, true), *v = last;
        for (; v && !v->ch[c]; v = v->next) v->ch[c] = u;

        if (!v) {
            u->next = start;
        } else if (v->ch[c]->max == v->max + 1) {
            u->next = v->ch[c];
        } else {
            // 节点 n 并没有表示一个新的后缀，所以它对 pos-end 集合的大小没有贡献
            Node *n = new (_curr++) Node(v->max + 1, false), *o = v->ch[c];
            copy(o->ch, o->ch + CHARSET_SIZE, n->ch);
            n->next = o->next;
            o->next = u->next = n;
            for (; v && v->ch[c] == o; v = v->next) v->ch[c] = n;
        }

        last = u;
        return u;
    }

    // 拓扑排序
    vector<Node *> &toposort() {
        static int buc[MAXN * 2 + 1];
        int max = 0;  // 记录最大值，方便清空 buc 数组
        // 普通的计数排序
        for (Node *p = _pool; p != _curr; p++) {
            max = max(max, p->max);
            buc[p->max]++;
        }
        for (int i = 1; i <= max; i++) buc[i] += buc[i - 1];

        topo.resize(_curr - _pool);
        for (Node *p = _pool; p != _curr; p++) {
            topo[--buc[p->max]] = p;
        }

        // 清空 buc 数组以便下一次使用
        fill(buc, buc + max + 1, 0);

        return topo;
    }

    void calc() {
        toposort();

        // 按照拓扑序，从子节点向父节点递推
        for (int i = topo.size() - 1; i > 0; i--)  // i > 0
        {
            Node *v = topo[i];
            v->next->posCnt += v->posCnt;
        }
    }
} sam;
int main() {
    freopen("RAW/in", "r", stdin);
    freopen("RAW/out", "w", stdout);
    return 0;
}
