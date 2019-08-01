#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int SIZE = 1e5+5;
int flag[SIZE];
int k;
void bfs(int n) {
    queue<int> que;
    que.push(n);
    while(!que.empty()) {
        int tt = que.front();
        que.pop();
        if(tt == k) break;
        for(int i = 0; i < 3; i++) {
            if(i == 0 && tt+1 <= SIZE-5 && flag[tt+1] == -1) {
                int temp = tt+1;
                flag[temp] = flag[tt]+1;
                que.push(temp);
            } else if(i == 1 && flag[tt-1] == -1) {
                int temp = tt-1;
                flag[temp] = flag[tt]+1;
                que.push(temp);
            } else if(i == 2 && tt*2 <= SIZE-5 && flag[tt*2] == -1) {
                int temp = tt*2;
                flag[temp] = flag[tt]+1;
                que.push(temp);
            }
        }
    }
}
int main() {
    int n;
    memset(flag, -1, sizeof(flag));
    scanf("%d%d", &n, &k);
    flag[n] = 0;
    bfs(n);
    printf("%d\n", flag[k]);
    return 0;
}