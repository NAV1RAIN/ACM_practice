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
const int MAXN = 2000010;
namespace SADA {
int t1[MAXN], t2[MAXN], c[MAXN];
//求 SA 数组需要的中间变量， 不需要赋值
//待排序的字符串放在 s 数组中， 从 s[0] 到 s[n-1]，长度为 n，且最大值小于 m，
//除 s[n-1] 外的所有 s[i] 都大于 0 ，r[n-1] = 0
//函数结束以后结果放在 sa 数组中
int rank[MAXN], height[MAXN], sa[MAXN];

bool cmp(int *r, int a, int b, int l) {
    return r[a] == r[b] && r[a + l] == r[b + l];
}
void da(int str[], int n, int m) {
    n++;
    int p, *x = t1, *y = t2;
    for (int i = 0; i < m; i++) c[i] = 0;
    for (int i = 0; i < n; i++) c[x[i] = str[i]]++;
    for (int i = 1; i < m; i++) c[i] += c[i - 1];
    for (int i = n - 1; i >= 0; i--) sa[--c[x[i]]] = i;
    for (int j = 1; j <= n; j <<= 1) {
        p = 0;
        //直接利用 sa 数组排序第二关键字
        for (int i = n - j; i < n; i++) y[p++] = i;  //后面的 j 个数第二关键字为空的最小
        for (int i = 0; i < n; i++)
            if (sa[i] >= j) y[p++] = sa[i] - j;
        //这样数组 y 保存的就是按照第二关键字排序的结果
        //基数排序第一关键字
        for (int i = 0; i < m; i++) c[i] = 0;
        for (int i = 0; i < n; i++) c[x[y[i]]]++;
        for (int i = 1; i < m; i++) c[i] += c[i - 1];
        for (int i = n - 1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];
        //根据 sa 和 x 数组计算新的 x 数组
        swap(x, y);
        p = 1;
        x[sa[0]] = 0;
        for (int i = 1; i < n; i++) {
            x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
        }
        if (p >= n) break;
        m = p;  //下次基数排序的最大值
    }
    int k = 0;
    n--;
    for (int i = 0; i <= n; i++) rank[sa[i]] = i;
    for (int i = 0; i < n; i++) {
        if (k) k--;
        int j = sa[rank[i] - 1];
        while (str[i + k] == str[j + k]) k++;
        height[rank[i]] = k;
    }
}
};  // namespace SADA
char str[MAXN];
int r[MAXN];
int main() {
    // freopen("RAW/in", "r", stdin);
    // freopen("RAW/out", "w", stdout);
    scanf("%s", str);
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        r[i] = str[i];
    }
    r[len] = 0;
    SADA::da(r, len, 128);
    for (int i = 1; i <= len; i++) {
        printf("%d ", SADA::sa[i] + 1);
    }
    return 0;
}