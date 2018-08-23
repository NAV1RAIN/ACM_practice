#include <cstdio>
#include <cstring>
using namespace std;

const int SIZE = 1e5 + 5;
const int MOD = 998244353;
long long a[SIZE];

int main(int argc, char const* argv[])
{
    int _;
    a[1] = a[2] = a[3] = 0;
    a[4] = 1;
    for (int i = 5; i < SIZE; i++) {
        a[i] = ((4 * a[i - 1]) % MOD + 4) % MOD;
    }
    for (scanf("%d", &_); _; _--) {
        int i;
        scanf("%d", &i);
        printf("%d\n", a[i]);
    }
    return 0;
}
