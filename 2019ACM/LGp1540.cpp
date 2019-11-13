#include <bits/stdc++.h>
using namespace std;
const int SIZE = 1005;
bool flag[SIZE];
queue<int> que;
int main() {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    int m, n;
    int ans = 0;
    scanf("%d%d", &m, &n);
    for(int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        if(!flag[num]) {
            flag[num] = true;
            ans++;
            if(que.size() == m) {
                flag[que.front()] = false;
                que.pop();
            }
            que.push(num);
        }
    }
    printf("%d\n", ans);
    return 0;
}