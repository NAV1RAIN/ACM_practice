#include <bits/stdc++.h>
using namespace std;
const int SIZE = 2e6+5;
char ss[SIZE];
bool jl[10][10];
int ans = 0;
void dfs(int hh) {
    if(ss[hh][ans]) {
        for(int i = 0; i < 6; i++) {
            
        }
    }
}
int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    int T;
    scanf("%d", &T);
    while(T--) {
        ans = 0;
        memset(jl, false, sizeof(jl));
        for(int i = 0; i < 6; i++) {
            scanf("%s", ss);
            int len = strlen(ss);
            for(int j = 0; j < len; j++) {
                if(ss[j] == 'h') jl[i][0] = true;
                else if(ss[j] == 'a') jl[i][1] = true;
                else if(ss[j] == 'r') jl[i][2] = true;
                else if(ss[j] == 'b') jl[i][3] = true;
                else if(ss[j] == 'i') jl[i][4] = true;
                else if(ss[j] == 'n') jl[i][5] = true;
            }
        }
    }
    dfs(0);
    return 0;
}