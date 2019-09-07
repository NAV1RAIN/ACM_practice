#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
char Ma[MAXN << 1];
int Mp[MAXN << 1];
void Manacher(char s[], int len) {
  int l = 0;
  Ma[l++] = '$';
  Ma[l++] = '#';
  for (int i = 0; i < len; i++) {
    Ma[l++] = s[i];
    Ma[l++] = '#';
  }
  Ma[l] = 0;
  int mx = 0, id = 0;
  for (int i = 0; i < l; i++) {
    Mp[i] = mx > i ? min(Mp[2 * id - i], mx - i) : 1;
    while (Ma[i + Mp[i]] == Ma[i - Mp[i]]) Mp[i]++;
    if (i + Mp[i] > mx) {
      mx = i + Mp[i];
      id = i;
    }
  }
}
char s[MAXN];
const int M = MAXN * 100;
int n, q, tot;
int a[MAXN];
int T[MAXN], lson[M], rson[M], c[M];
int build(int l, int r) {
  int root = tot++;
  c[root] = 0;
  if (l != r) {
    int mid = (l + r) >> 1;
    lson[root] = build(l, mid);
    rson[root] = build(mid + 1, r);
  }
  return root;
}
int update(int root, int pos, int val) {
  int newroot = tot++, tmp = newroot;
  c[newroot] = c[root] + val;
  int l = 1, r = n;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (pos <= mid) {
      lson[newroot] = tot++;
      rson[newroot] = rson[root];
      newroot = lson[newroot];
      root = lson[root];
      r = mid;
    } else {
      rson[newroot] = tot++;
      lson[newroot] = lson[root];
      newroot = rson[newroot];
      root = rson[root];
      l = mid + 1;
    }
    c[newroot] = c[root] + val;
  }
  return tmp;
}
int query(int root, int pos) {
  int ret = 0;
  int l = 1, r = n;
  while (pos < r) {
    int mid = (l + r) >> 1;
    if (pos <= mid) {
      r = mid;
      root = lson[root];
    } else {
      ret += c[lson[root]];
      root = rson[root];
      l = mid + 1;
    }
  }
  return ret + c[root];
}
int main() {
  freopen("RAW/in", "r", stdin);
  freopen("RAW/out", "w", stdout);
  while (~scanf("%s", s)) {
    int len = strlen(s);
    for (int i = 1; i <= len; i++) {
      a[i] = (int)s[i - 1];
    }
    T[len + 1] = build(1, len);
    map<int, int> mp;
    for (int i = len; i >= 1; i--) {
      if (mp.find(a[i]) == mp.end()) {
        T[i] = update(T[i + 1], i, 1);
      } else {
        int tmp = update(T[i + 1], mp[a[i]], -1);
        T[i] = update(tmp, i, 1);
      }
      mp[a[i]] = i;
    }
    Manacher(s, len);
    long long ans = 0;
    for (int i = 0; i < 2 * len + 2; i++) {
      int hh = Mp[i] - 1;
      if (hh > 0) {
        if (hh == 1) {
          ans += 1;
          continue;
        }
        int L, R;
        if (i & 1) {
          int ttt = hh / 2;
          L = i / 2 - ttt + 1;
          R = i / 2 + ttt;
        } else {
          int ttt = (hh - 1) / 2;
          L = i / 2 - ttt;
          R = i / 2 + ttt;
        }
        long long fuck = query(T[L], R);
        ans += (fuck + 1LL) * fuck / 2LL;
      }
      // printf("%d ", Mp[i] - 1);
      // jl += Mp[i] - 1;
      // ans = max(ans, Mp[i] - 1);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
// abac