#include <iostream>
using namespace std;
const int p = 1e9 + 7;
long long pow(long long a, long long b) {
  long long ans = 1, base = a;
  while (b) {
    if (b & 1) {
      ans = ans * base % p;
    }
    base = base * base % p;
    b = b >> 1;
  }
  return ans;
}
int main() {
  // freopen("RAW\\in.txt", "r", stdin);
  // freopen("RAW\\out.txt", "w", stdout);
  int t;
  long long n;
  scanf("%d", &t);
  while (t--) {
    scanf("%lld", &n);
    long long ans = pow(24, p - 2);
    ans = ans * n % p;
    ans = ans * (n + 1) % p;
    ans = ans * (n + 2) % p;
    ans = ans * (n + 3) % p;
    printf("%lld\n", ans);
  }
  return 0;
}
