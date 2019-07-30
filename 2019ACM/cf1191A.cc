#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("RAW/in", "r", stdin);
    // freopen("RAW/out", "w", stdout);
    int x;
    char str[10] = "DACB";
    scanf("%d", &x);
    char t = str[x%4];
    int jl = 0;
    if(t > str[((x%4)+1)%4]) {
        jl = 1;
        t = str[((x%4)+1)%4];
    }
    if(t > str[((x%4)+2)%4]) {
        jl = 2;
        t = str[((x%4)+2)%4];
    }
    printf("%d %c", jl, t);
    return 0;
}