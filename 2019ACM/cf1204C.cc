#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL LNF = 0x3f3f3f3f3f3f3f3f;
const int SIZE = 105;
char maze[SIZE][SIZE];
int jl[SIZE];
int arr[SIZE];
vector<int> ans;
int main() {
    // freopen("RAW/in", "r", stdin);
    // freopen("RAW/out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", maze[i]+1);
    }
    int m;
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 1; i <= m; i++) {
        if (maze[arr[i - 1]][arr[i + 1]] == '1' || i == 1 || i == m || arr[i-1] == arr[i+1]) {
            ans.push_back(arr[i]);
        }
    }
    int len = ans.size();
    printf("%d\n", len);
    for(vector<int>::iterator it = ans.begin(); it != ans.end(); it++) {
        if(it != ans.begin()) printf(" ");
        printf("%d", *it);
    }
    printf("\n");
    return 0;
}
