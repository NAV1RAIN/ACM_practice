#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

void BTree(int* id, int* od, int len) {
    if(len == 0) return ;
    int rootIndex = 0;
    for(; rootIndex < len; rootIndex++) {
        if(id[rootIndex] == *od) {
            break;
        }
    }
    BTree(id, od+1, rootIndex);
    BTree(id+rootIndex+1, od+rootIndex+1, len-rootIndex-1);
    printf("%d ", *od);
    return ;
}

int main() {
    // freopen("RAW/in", "r", stdin);
    // freopen("RAW/out", "w", stdout);
    int n;
    scanf("%d", &n);
    int aa[50] = {0};
    int bb[50] = {0};
    for(int i = 0; i < n; i++) {
        scanf("%d", &aa[i]);
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &bb[i]);
    }
    BTree(bb, aa, n);
    printf("\n");
    return 0;
}