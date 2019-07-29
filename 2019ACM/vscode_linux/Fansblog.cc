#include <bits/stdc++.h>
#define maxn 0x7fffffff

using namespace std;

typedef long long ll;
const int S = 8;  //随机算法判定次数一般 8"<10 就够了
// 计算 ret = (a*b)%c a,b,c < 2^63
long long mult_mod(long long a, long long b, long long c) {
    a %= c;
    b %= c;
    long long ret = 0;
    long long tmp = a;

    while (b) {
        if (b & 1) {
            ret += tmp;

            if (ret > c) ret -= c;  //直接取模慢很多
        }

        tmp <<= 1;

        if (tmp > c) tmp -= c;

        b >>= 1;
    }

    return ret;
}
// 计算 ret = (a^n)%mod
long long pow_mod(long long a, long long n, long long mod) {
    long long ret = 1;
    long long temp = a % mod;

    while (n) {
        if (n & 1) ret = mult_mod(ret, temp, mod);

        temp = mult_mod(temp, temp, mod);
        n >>= 1;
    }

    return ret;
}
// 通过 a^(n-1)=1(mod n)来判断 n 是不是素数
// n - 1 = x " 2
// 是合数返回 true, 不一定是合数返回 false
bool check(long long a, long long n, long long x, long long t) {
    long long ret = pow_mod(a, x, n);
    long long last = ret;

    for (int i = 1; i <= t; i++) {
        ret = mult_mod(ret, ret, n);

        if (ret == 1 && last != 1 && last != n - 1) return true;  //合数

        last = ret;
    }

    if (ret != 1)
        return true;
    else
        return false;
}
//**************************************************
// Miller_Rabin 算法
// 是素数返回 true,(可能是伪素数)
// 不是素数返回 false
//**************************************************
bool Miller_Rabin(long long n) {
    if (n < 2) return false;

    if (n == 2) return true;

    if ((n & 1) == 0) return false;  //偶数

    long long x = n - 1;
    long long t = 0;

    while ((x & 1) == 0) {
        x >>= 1;
        t++;
    }

    srand(time(NULL)); /* *************** */

    for (int i = 0; i < S; i++) {
        long long a = rand() % (n - 1) + 1;

        if (check(a, n, x, t)) return false;
    }

    return true;
}

//**********************************************
// pollard_rho 算法进行质因素分解
//*********************************************
long long factor[100];  //质因素分解结果（刚返回时时无序的）
int tol;                //质因素的个数，编号 0"<tol-1

long long gcd(long long a, long long b) {
    long long t;

    while (b) {
        t = a;
        a = b;
        b = t % b;
    }

    if (a >= 0)
        return a;
    else
        return -a;
}

//找出一个因子
long long pollard_rho(long long x, long long c) {
    long long i = 1, k = 2;
    srand(time(NULL));
    long long x0 = rand() % (x - 1) + 1;
    long long y = x0;

    while (1) {
        i++;
        x0 = (mult_mod(x0, x0, x) + c) % x;
        long long d = gcd(y - x0, x);

        if (d != 1 && d != x) return d;

        if (y == x0) return x;

        if (i == k) {
            y = x0;
            k += k;
        }
    }
}
//对 n 进行素因子分解，存入 factor. k 设置为 107 左右即可
void findfac(long long n, int k) {
    if (n == 1) return;

    if (Miller_Rabin(n)) {
        factor[tol++] = n;
        return;
    }

    long long p = n;
    int c = k;

    while (p >= n) p = pollard_rho(p, c--);  //值变化，防止死循环 k

    findfac(p, k);
    findfac(n / p, k);
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;

    while (T--) {
        ll num;
        cin >> num;
        ll tmp = 1;
        ll i;

        for (ll i = num - 2;; i--) {
            if (Miller_Rabin(i)) break;

            tmp = ((tmp % num) * (i % num)) % num;
        }

        //
        //        for (ll index = num - i + 1; index <= num - 2; ++index)
        //            tmp = ((tmp % num) * (index % num)) % num;

        ll ans = pow_mod(tmp, num - 2, num);
        cout << ans << endl;
    }

    return 0;
}