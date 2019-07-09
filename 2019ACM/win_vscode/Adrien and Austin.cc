#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    // freopen("RAW/in.txt", "r", stdin);
    // freopen("RAW/out.txt", "w", stdout);
    int n, k;
    while(scanf("%d%d", &n, &k) != EOF) {
        int s = n/k;
        int y = n%k;
        if(n == 0) {
            printf("Austin\n");
            continue;
        }
        if((s%2 == 1 && y == 0) || (s%2 == 0 && y != 0)) {
            printf("Adrien\n");
        } else {
            printf("Austin\n");
        }
    }
    return 0;
}