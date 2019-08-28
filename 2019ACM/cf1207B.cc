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
typedef pair<int,int> pp;
const int INF = 0x3f3f3f3f;
const LL LNF = 0x3f3f3f3f3f3f3f3f;
const int SIZE = 105;
int arr[SIZE][SIZE];
int tt[SIZE][SIZE];
int maze[SIZE][SIZE];
vector<pp> ans;
int main() {
    // freopen("RAW/in", "r", stdin);
    // freopen("RAW/out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    bool flag = true;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(arr[i][j]) {
                if(arr[i][j+1]&&arr[i+1][j]&&arr[i+1][j+1]) {
                    ans.push_back(pp(i,j));
                    tt[i][j]=1;
                    tt[i][j+1]=1;
                    tt[i+1][j]=1;
                    tt[i+1][j+1]=1;
                }
            }
        }
    }
    for(int i = 1; i <= n && flag; i++) {
        for(int j = 1; j <= m && flag; j++) {
            if(arr[i][j] != tt[i][j]) flag = false;
        }
    }
    if(!flag) printf("-1\n");
    else {
        printf("%d\n", ans.size());
        for(auto it = ans.begin(); it != ans.end(); it++) {
            printf("%d %d\n", (*it).first, (*it).second);
        }
    }
    return 0;
}
