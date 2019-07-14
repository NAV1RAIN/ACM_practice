#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;
char s[MAXN], t[MAXN], p[MAXN];
int arr[30], brr[30];
int main() {
    // freopen("RAW/in", "r", stdin);
    // freopen("RAW/out", "w", stdout);
    int q;
    scanf("%d", &q);
    while(q--) {
        memset(arr, 0, sizeof(arr));
        memset(brr, 0, sizeof(brr));
        scanf("%s%s%s", s, t, p);
        int jl = 0;
        int lenS = strlen(s), lenT = strlen(t), lenP = strlen(p);
        for(int i = 0; i < lenT; i++) {
            brr[t[i]-'a']++;
            if(t[i] == s[jl]) {
                jl++;
            }
        }
        bool flag = jl == lenS;
        if(!flag) {
            printf("NO\n");
        } else {
            for(int i = 0; i < lenS; i++) {
                arr[s[i]-'a']++;
            }
            for(int i = 0; i < 26 && flag; i++) {
                if(arr[i] > brr[i]) flag = false;
            }
            for(int i = 0; i < lenP && flag; i++) {
                arr[p[i]-'a']++;
            }
            
            for(int i = 0; i < 26 && flag; i++) {
                if(arr[i] < brr[i]) flag = false;
            }
            printf("%s\n", flag?"YES":"NO");
        }
    }
    return 0;
}