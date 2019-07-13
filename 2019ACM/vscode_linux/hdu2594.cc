#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 1e5+5;
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
char s1[MAXN];
int main() {
    // freopen("RAW/in", "r", stdin);
    // freopen("RAW/out", "w", stdout);
    while (scanf("%s", s1) != EOF) {
        memset(next, 0, sizeof(next));
        int m = strlen(s1);
        s1[m] = -1;
        printf("%d\n", s1[m]);
        scanf("%s", s1+m+1);
        m = strlen(s1);
        kmp_pre(s1, next);
        if(next[m] != 0) {
            for(int i = 0; i < next[m]; i++) {
                printf("%c", s1[i]);
            }
            printf(" %d\n", next[m]);
        } else {
            printf("0\n");
        }
    }
    return 0;
}