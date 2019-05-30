#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5+5;
char Ma[MAXN*2];
int Mp[MAXN*2];
void Manacher(char s[], int len) {
    int l = 0;
    Ma[l++] = '$';
    Ma[l++] = '#';
    for(int i = 0; i < len; i++) {
        Ma[l++] = s[i];
        Ma[l++] = '#';
    }
    Ma[l] = 0;
    int mx = 0, id = 0;
    for(int i = 0; i < l; i++) {
        Mp[i] = mx>i?min(Mp[2*id-i], mx-i):1;
        while(Ma[i+Mp[i]]==Ma[i-Mp[i]]) Mp[i]++;
        if(i + Mp[i] > mx) {
            mx = i+Mp[i];
            id = i;
        }
    }
}
char ss[MAXN];
char s[MAXN];
int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    char tt;
    while(scanf("%c", &tt) != EOF) {
        memset(s, '\0', sizeof(s));
        memset(ss, '\0', sizeof(ss));
        scanf("%s", ss);
        getchar();
        int len = strlen(ss);
        for(int i = 0; i < len; i++) {
            int t = ss[i]-tt;
            s[i] = t >= 0 ? 'a'+t : 'z'+1+t;
        }
        Manacher(s, len);
        int ans = 0;
        int id = 0;
        for(int i = 0; i < 2*len+2; i++) {
            if(ans < Mp[i]-1) {
                id = i;
                ans = Mp[i]-1;
            }
        }
        if(ans == 1) printf("No solution!");
        else {
            id /= 2;
            int l = id-ans/2;
            if(ans & 1) l--;
            printf("%d %d\n", l, ans+l-1);
            for(int i = l; i < ans+l; i++) {
                printf("%c", s[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
