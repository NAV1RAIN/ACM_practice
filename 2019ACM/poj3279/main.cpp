#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int m, n;
int arr[20][20];
int main() {
    scanf("%d%d", &m, &n);
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    return 0;
}