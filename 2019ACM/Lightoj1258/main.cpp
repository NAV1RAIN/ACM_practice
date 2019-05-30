#include <bits/stdc++.h>
using namespace std;
const int SIZE = 1e6+5;
void kmp_pre(char x[], int m, int Next[]) {
    int i, j;
    j = Next[0] = -1;
    i = 0;
    while(i < m) {
        while(-1 != j && x[i] != x[j]) j = Next[j];
        Next[++i] = ++j;
    }
}
int Next[SIZE];
int KMP_Count(char x[], int m, char y[], int n) {
    int i, j;
    int ans = 0;
    kmp_pre(x, m, Next);
    i = j = 0;
    while(i < n) {
        while(-1 != j && y[i] != x[j]) j = Next[j];
        i++;
        j++;
        if(j > m) {
            ans++;
            j = Next[j];
        }
    }
    return j;
}

char str1[SIZE];
char str2[SIZE];
int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int T, time = 1;
    scanf("%d", &T);
    while(T--) {
        memset(str1, 0, sizeof(str1));
        memset(str2, 0, sizeof(str2));
        scanf("%s", str1);
        int len = strlen(str1);
        if(len == 1) {
            printf("Case %d: 1\n", time++);
            continue;
        }
        for(int i = 0; i < len; i++) {
            str2[len-i-1] = str1[i];
        }
//        printf("%s\n", str2);
        int tt = KMP_Count(str2, len, str1, len);
//        printf("%d\n", tt);
        printf("Case %d: %d\n", time++, len+len-tt);
    }
    return 0;
}
