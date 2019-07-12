#include <cstdio>
using namespace std;

const int SIZE = 100006;
int node[SIZE];
bool ok[SIZE];
void Init() {
    for (int i = 0; i <= SIZE; i++) {
        node[i] = i, ok[i] = false;
    }
}
int Find(int x) {
    if (x != node[x]) node[x] = Find(node[x]);
    return node[x];
}
void Unit(int x, int y) {
    x = Find(x);
    y = Find(y);
    node[y] = x;
}

int main() {
    int a, b;
    while (~scanf("%d%d", &a, &b)) {
        if (a == -1 && b == -1) break;
        Init();
        int FLAG = 0;
        while (1) {
            if (a == 0 && b == 0) break;
            if (Find(a) == Find(b)) FLAG = 1;
            Unit(a, b);
            ok[a] = 1, ok[b] = 1;
            scanf("%d%d", &a, &b);
        }
        if (FLAG == 1)
            printf("No\n");
        else {
            int sum = 0;
            for (int i = 0; i <= 100000; i++)
                if (ok[i] && node[i] == i) sum++;
            if (sum > 1)
                printf("No\n");
            else
                printf("Yes\n");
        }
    }
    return 0;
}