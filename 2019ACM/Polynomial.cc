#include <bits/stdc++.h>
using namespace std;
vector<int> s1, s2;
int main() {
    // freopen("RAW/in", "r", stdin);
    // freopen("RAW/out", "w", stdout);
    int T;
    scanf("%d", &T);
    while(T--) {
        s1.clear();
        s2.clear();
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            int tt;
            scanf("%d", &tt);
            s1.push_back(tt);
        }
        for(int i = 0; i < n; i++) {
            int tt;
            scanf("%d", &tt);
            s2.push_back(tt);
        }
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        int a1, a2;
        a1 = a2 = -1;
        for(vector<int>::iterator it1 = s1.begin(), it2 = s2.begin(); it1 != s1.end() && it2 != s2.end(); it1++, it2++) {
            if(*it1 == 0 && *it2 == 0) continue;
            else if(*it2 == 0) break;
            else {
                a1 = *it1;
                a2 = *it2;
                break;
            }
        }
        if(a1 == -1 && a2 == -1) printf("1/0\n");
        else {
            if(a1 == 0) {
                printf("0/1\n");
                continue;
            }
            int temp = __gcd(a1, a2);
            a1 /= temp;
            a2 /= temp;
            printf("%d/%d\n", a1, a2);
        }
    }
    return 0;
}