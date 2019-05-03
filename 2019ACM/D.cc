#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
ll p, n, k;

ll quickpow(ll a, ll b)
{
    if (b < 0) return 0;
    ll ret = 1;
    a %= p;
    while(b)
    {
        if (b & 1) ret = (ret * a) % p;
        b >>= 1;
        a = (a * a) % p;
    }
    return ret;
}

ll inv(ll a)
{
    return quickpow(a, p - 2);
}

int main()
{
//    freopen("in.txt", "r", stdin);
    cin >> n >> k >> p;
    ll ans = 0, nn = n;
    int len = 0;
    if(p == 2)
    {
        if(ans == 1) cout << 1 << endl;
        else
            cout << 0 << endl;
        return 0;
    }
//    cout<<n<<" "<<k<<endl;
    ll t = 1 << n;
    ll anss = quickpow(2ll, t);
    ll az = inv(t);
    ll ansss = anss * az % p;
    cout << ansss << endl;
    return 0;
}
