#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL LNF = 0x3f3f3f3f3f3f3f3f;
const int SIZE = 2005;
char maze[SIZE][SIZE];
int main() {
    freopen("RAW/in", "r", stdin);
    freopen("RAW/out", "w", stdout);
    int T;
    scanf("%d", &T);
    while(T--) {
        int k;
        scanf("%d", &k);
        int nn = 1 << k;
        for(int i = 0; i < nn; i++) {
            maze[0][i] = 'C';
        }
        for(int i = 0; i < nn; i++) {
            if(i%2 == 0) maze[1][i] = 'P';
            else maze[1][i] = 'C';
        }
        for(int i = 3; i < nn; i += 2) {
            for(int j = 3; j < nn; j += 4) {
                maze[i][j] = 
            }
        }
    }    
    return 0;
}
