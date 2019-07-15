#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+5;
const int MOD = 1e9+7;
char s1[MAXN], s2[MAXN];
int ans[MAXN];
void kmp_pre(char x[], int next[]) {
    int i, j;
    j = next[0] = -1;
    i = 0;
    int m = strlen(x);
    while(i < m) {
        while(-1 != j && x[i] != x[j]) j = next[j];
        next[++i] = ++j;
    }
}
void KMP_Count(char x[], char y[], int next[]) {   //s2,s1
    int i, j;
    i = j = 0;
    int m = strlen(x), n = strlen(y);
    while(i <= n) {
        if(i == n) {
            int l = 5;
        }
        while(-1 != j && y[i] != x[j]) {
            ans[j]++;
            j = next[j];
        }
        i++;
        j++;
        if(j >= m) {
            ans[m]++;
            j = next[j];
        }
    }
}
int next1[MAXN];
int next2[MAXN];
int main() {
    freopen("RAW/in", "r", stdin);
    freopen("RAW/out", "w", stdout);
    int T;
    scanf("%d", &T);
    while(T--) {
        memset(ans, 0, sizeof(ans));
        memset(next1, 0, sizeof(next1));
        memset(next2, 0, sizeof(next2));
        scanf("%s%s", s1, s2);
        int lenS1 = strlen(s1), lenS2 = strlen(s2);
        for(int i = 0; i < lenS1/2; i++) {
            swap(s1[i], s1[lenS1-i-1]);
        }
        for(int i = 0; i < lenS2/2; i++) {
            swap(s2[i], s2[lenS2-i-1]);
        }
        // printf("%s\n%s\n", s1, s2);
        kmp_pre(s1, next1);
        kmp_pre(s2, next2);
        KMP_Count(s2, s1, next2);
        long long num = 0;
        // printf("%d\n", ans[lenS2]);
        for(int i = lenS2-1; i >= 1; i--) {
            ans[i] += ans[i+1];
            if(ans[i] >= MOD) ans[i] -= MOD;
        }
        for(int i = 1; i <= lenS2; i++) {
            num += (long long)i*ans[i]%MOD;
            if(num >= MOD) num -= MOD;
        }
        printf("%lld\n", num%MOD);
        // for(int i = 0; i <= lenS1; i++) {
        //     printf("%d ", next1[i]);
        // }
        // printf("\n");
        // for(int i = 0; i <= lenS2; i++) {
        //     printf("%d ", next2[i]);
        // }
        // printf("\n\n");
    }
    return 0;
}