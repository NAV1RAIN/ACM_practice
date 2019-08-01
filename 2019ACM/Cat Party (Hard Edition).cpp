#include <bits/stdc++.h>
using namespace std;
const int SIZE = 1e5+5;
int u[SIZE];
int a[SIZE];
int b[SIZE];
set<int> st;
int main() {
    int n;
    scanf("%d", &n);
    int ans = 2;
    for(int i = 1; i <= n; i++) {
        int temp;
        scanf("%d", &temp);
        if(b[a[temp]] > 0) {
            b[a[temp]]--;
            if(b[a[temp]] == 0) st.erase(a[temp]);
        }
        a[temp]++;
        b[a[temp]]++;
        st.insert(a[temp]);
        if(st.size() == 1) {
            if(i < n || st.count(1)) ans = i+1;
        } else if(st.size() == 2) {
            if(b[1] == 1) ans = i;
            else {
                int x, y;
                for(auto it = st.begin(); it != st.end(); it++) {
                    if(it == st.begin()) x = *it;
                    else y = *it;
                }
                if(abs(x-y) == 1 && b[y] == 1) ans = i;
            }
        }
    }
    if(ans > n) ans = n;
    printf("%d\n", ans);
    return 0;
}
