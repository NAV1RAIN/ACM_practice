#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
int Ma[MAXN*2];
int Mp[MAXN*2];
void Manacher(int s[], int len) {
    int l = 0;
    Ma[l++] = -1;
    Ma[l++] = -2;
    for(int i = 0; i < len; i++) {
        Ma[l++] = s[i];
        Ma[l++] = -2;
    }
    Ma[l] = 0;
    int mx = 0, id = 0;
    for(int i = 0; i < l; i++) {
        Mp[i] = mx>i?min(Mp[2*id-i], mx-i):1;
        while(Ma[i+Mp[i]] == Ma[i-Mp[i]] && Ma[i-Mp[i]] <= Ma[i-Mp[i]+2]) Mp[i]++;
        if(i+Mp[i] > mx) {
            mx = i+Mp[i];
            id = i;
        }
    }
}
int s[MAXN];
int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int T;
    while(scanf("%d", &T) != EOF) {
        while(T--) {
            int n;
            scanf("%d", &n);
            for(int i = 0; i < n; i++) {
                scanf("%d", &s[i]);
            }
            Manacher(s, n);
            int ans = 0;
            for(int i = 0; i < 2*n+2; i++) {
                ans = max(ans, Mp[i]-1);
            }
            if(ans == 0) ans = 1;
            printf("%d\n", ans);
        }
    }
    return 0;
}
