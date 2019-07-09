#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef long long ll;
//素数筛法
const int Max = 1e6 + 50;
int prime[Max], pNum = 0; // pNum存放素数个数
int pos[Max];
bool p[Max] = {false};
void findPrime() {
  for (int i = 2; i < Max; i++) //遍历从2到100的数
  {
    if (p[i] == false) //若i为素数
    {
      prime[pNum++] = i; //将i添加到prime数组中
      pos[i] = pNum - 1;
      for (int j = i + i; j < Max; j += i) //筛掉i的倍数
      {
        p[j] = true;
      }
    }
  }
}

int pre[Max];
int main() {
  freopen("RAW\\in.txt", "r", stdin);
  freopen("RAW\\out.txt", "w", stdout);
  findPrime();
  for (int i = 0; i < pNum; i++)
    pre[i] = 0;
  int n;
  scanf("%d", &n);
  int x;
  int ans = 0;
  //    for(int i = 0;i<pNum;i++) cout<<prime[i]<<endl;
  for (int j = 1; j <= n; j++) {
    scanf("%d", &x);
    if (x == 1)
      continue;
    int i;
    for (i = 0; i < pNum; i++) {
      //            cout<<prime[i]<<endl;
      if (prime[i] * prime[i] <= x) {
        if (x % prime[i] == 0) {
          cout << prime[i] << endl;
          cout << "+" << (j - pre[i]) * (n - j + 1) << endl;
          ans += (j - pre[i]) * (n - j + 1);
          pre[i] = j;
          if (!p[x / prime[i]] && prime[i] * prime[i] != x) {
            cout << x / prime[i] << endl;
            int t = pos[x / prime[i]];
            ans += (j - pre[t]) * (n - j + 1);
            cout << "+" << (j - pre[t]) * (n - j + 1) << endl;
            pre[t] = j;
          }
        }

      } else {
        break;
      }
    }
    if (!p[x]) {
      cout << x << endl;
      i = pos[x];
      ans += (j - pre[i]) * (n - j + 1);
      cout << "+" << (j - pre[i]) * (n - j + 1) << endl;
      pre[i] = j;
    }
    cout << ans << endl;
    cout << endl;
  }
  cout << ans << endl;
  return 0;
}
