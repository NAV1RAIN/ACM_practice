#include <bits/stdc++.h>
using namespace std;
const int SIZE = 1e5+5;
char str1[SIZE], str2[SIZE];
vector<int> jl2;
int main() {
    freopen("RAW/in", "r", stdin);
    freopen("RAW/out", "w", stdout);
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%s%s", str1, str2);
        int len1 = strlen(str1);
        int len2 = strlen(str2);
        int jl1 = -1;
        for (int i = len2 - 1; i >= 0; i--) {
            if(str2[i] == '1') {
                jl1 = i;
                break;
            }
        }
        int ll = len2-1-jl1;
        int ans = 0;
        for (int i = len1-1-ll; i >= 0; i--) {
            if(str1[i] == '1') break;
            ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}