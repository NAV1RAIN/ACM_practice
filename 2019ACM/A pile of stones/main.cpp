#include <bits/stdc++.h>
using namespace std;

int main()
{
    char str[110];
    int ans = 0, n;
    scanf("%d", &n);
    scanf("%s", str);
    for(int i = 0; i < n; i++) {
        if(str[i] == '-') {
            ans--;
            if(ans < 0) ans = 0;
        } else if(str[i] == '+') {
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
