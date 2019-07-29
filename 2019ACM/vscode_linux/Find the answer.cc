#include <bits/stdc++.h>

#define debug(x) cout << "[" << #x << ": " << (x) << "]" << endl
#define pii pair<LL, LL>
#define clr(a, b) memset((a), b, sizeof(a))
#define rep(i, a, b) for (LL i = a; i < b; i++)
#define pb push_back
#define MP make_pair
#define LL long long
#define ull unsigned LL
#define ls i << 1
#define rs (i << 1) + 1

using namespace std;

const LL maxn = 2e5 + 10;
LL sum[maxn << 2];
LL C[maxn << 2];
LL t[maxn], K[maxn];

void update(LL l, LL r, LL p, LL i) {
    if (l == r) {
        ++sum[i];
        C[i] += K[p];
        return;
    }
    LL mid = (l + r) >> 1;
    if (p <= mid) update(l, mid, p, i << 1);
    if (p > mid) update(mid + 1, r, p, i << 1 | 1);
    sum[i] = sum[i << 1] + sum[i << 1 | 1];
    C[i] = C[i << 1] + C[i << 1 | 1];
}

LL query(LL l, LL r, LL k, LL i) {
    if (l == r) return k >= sum[i] ? C[i] : C[i] / sum[i] * k;
    LL ans = 0, mid = (l + r) >> 1;
    if (sum[i << 1 | 1] >= k) {
        ans += query(mid + 1, r, k, i << 1 | 1);
    } else {
        ans += C[i << 1 | 1];
        ans += query(l, mid, k - sum[i << 1 | 1], i << 1);
    }
    return ans;
}

LL en;
LL getId(LL x) { return lower_bound(K + 1, K + 1 + en, x) - K; }

int main() {
    // freopen("RAW/in", "r", stdin);
    // freopen("RAW/out", "w", stdout);
    LL n, M;
    LL T;
    scanf("%lld", &T);
    while (T--) {
        scanf("%lld%lld", &n, &M);
        clr(sum, 0);
        clr(C, 0);
        for (LL i = 1; i <= n; ++i) {
            scanf("%lld", &t[i]);
            K[i] = t[i];
        }
        sort(K + 1, K + 1 + n);
        en = unique(K + 1, K + 1 + n) - K - 1;
        LL sum = 0;
        for (LL i = 1; i <= n; ++i) {
            if (i == 1) {
                printf("0 ");
                update(1, en, getId(t[i]), 1);
                sum += t[i];
                continue;
            }
            LL l = 0, r = i - 1;
            LL ans = r;
            while (l <= r) {
                LL mid = (l + r) >> 1;
                //                debug(mid);
                //                debug(query(1,en,mid,1));
                if (M - (sum - query(1, en, mid, 1)) >= t[i]) {
                    ans = min(ans, mid);
                    r = mid - 1;
                } else
                    l = mid + 1;
            }
            printf("%lld ", ans);
            update(1, en, getId(t[i]), 1);
            sum += t[i];
        }
        printf("\n");
    }
    return 0;
}