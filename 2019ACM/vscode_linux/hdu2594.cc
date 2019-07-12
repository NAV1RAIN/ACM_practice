#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 5e4 + 5;
void kmp_pre(char x[], int next[]) {
    int i, j;
    j = next[0] = -1;
    i = 0;
    int m = strlen(x);
    while (i < m) {
        while (-1 != j && x[i] != x[j]) j = next[j];
        next[++i] = ++j;
    }
}
int next[MAXN];
char s1[MAXN], s2[MAXN];
int main() {
    freopen("RAW/in", "r", stdin);
    freopen("RAW/out", "w", stdout);
    while (scanf("%s", s1) != EOF) {
        memset(next, 0, sizeof(next));
        printf("%d\n", ans);
        int m = strlen(s1), n = strlen(s2);
        for(int i = 0; i <= m; i++) {
            printf("%d ", next[i]);
        }
        printf("\n");
        if (!ans) {
            bool flag = true;
            for (int i = 0; i < m; i++) {
                if (s1[i] != s2[n - m + i]) flag = false;
            }
            if (!flag) {
                printf("0\n");
            } else {
                printf("%s %d\n", s1, m);
            }
        } else {
            for (int i = 0; i < ans; i++) {
                printf("%c", s1[i]);
            }
            printf(" %d\n", ans);
        }
    }
    return 0;
}