#include <bits/stdc++.h>
using namespace std;
const int SIZE = 1e6+5;
char str[SIZE];
char ans[SIZE];
int tot;
int main() {
    // freopen("RAW/in", "r", stdin);
    // freopen("RAW/out", "w", stdout);
    scanf("%s", str);
    int len = strlen(str);
    for(int i = 0; i+1 < len/2; i += 2) {
        if((str[i] == 'a' || str[i+1] == 'a') && (str[len-1-i] == 'a' || str[len-2-i] == 'a')) ans[tot++] = 'a';
        else if((str[i] == 'b' || str[i+1] == 'b') && (str[len-1-i] == 'b' || str[len-2-i] == 'b')) ans[tot++] = 'b';
        else if((str[i] == 'c' || str[i+1] == 'c') && (str[len-1-i] == 'c' || str[len-2-i] == 'c')) ans[tot++] = 'c';
    }
    printf("%s", ans);
    if(len%4 != 0) printf("%c", str[len/2]);
    reverse(ans, ans+tot);
    printf("%s\n", ans);
    return 0;
}