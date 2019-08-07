#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int SIZE = 1e5 + 5;
const int MAXN = 1e4 + 4;
struct Node {
    int len1, len2;
    char str1[10];
    char str2[10];
    Node() : len1(0), len2(0) {}
} ss[SIZE];
bool cmp(const Node& a, const Node& b) {
    return strcmp(a.str2, b.str2) <= 0;
}
char jihe[10][MAXN][10];
int tol;
int jl[10];
void solve(int n) {
    memset(ss, 0, sizeof(ss));
    tol = 0;
    char arr[10] = {'1', '2', '3', '4', '5', '6', '7', '8'};
    do {
        for (int i = 0; i < n; i++) {
            ss[tol].str1[ss[tol].len1++] = arr[i];
        }
        tol++;
    } while (next_permutation(arr, arr + n));
    for (int i = 0; i < tol; i++) {
        for (int j = 1; j < n; j++) {
            ss[i].str2[ss[i].len2++] = (ss[i].str1[j] - ss[i].str1[j - 1] + '0');
        }
    }
    sort(ss, ss + tol, cmp);
    if (n == 8) {
        for (int i = 0; i < tol; i++) {
            strcpy(jihe[8][jl[8]++], ss[i].str1);
            if(jl[8] == 10001) break;
        }
        for (int i = 0; i < tol; i++) {
            if (ss[i].str1[0] == '1') {
                strcpy(jihe[9][jl[9]++], ss[i].str1);
            }
        }
        for (int i = 0; i < tol; i++) {
            if (ss[i].str1[0] == '2') {
                strcpy(jihe[9][jl[9]++], ss[i].str1);
            }
            if (jl[9] == 10001) break;
        }
    } else {
        for(int i = 0; i < tol; i++) {
            strcpy(jihe[n][jl[n]++], ss[i].str1);
        }
    }
}
int main() {
    // freopen("RAW/in", "r", stdin);
    // freopen("RAW/out", "w", stdout);
    for(int i = 1; i <= 8; i++) {
        solve(i);
    }
    // for(int i = 0; i < jl[9]; i++) {
    //     printf("%s\n", jihe[9][i]);
    // }
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        long long k;
        scanf("%d%lld", &n, &k);
        k = min((long long)10000, k);
        if(n > 8) {
            printf("%d", n);
            for(int i = 1; i <= n-9; i++) {
                printf(" %d", i);
            }
            for(int i = 0; i < 8; i++) {
                printf(" %d", (int)(jihe[9][k-1][i]-'0'+(n-9)));
            }
        } else {
            for(int i = 0; i < n; i++) {
                if(i > 0) printf(" ");
                printf("%c", jihe[n][k-1][i]);
            }
        }
        printf("\n");
    }
    return 0;
}
//4960th 2 8 7 3 5 4 6 1