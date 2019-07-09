#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int SIZE = 105;

char str[SIZE];
int main()
{
    // freopen("RAW\\in.txt", "r", stdin);
    // freopen("RAW\\out.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    scanf("%s", str);
    int len = strlen(str);
    int one, zero;
    one = zero = 0;
    for(int i = 0; i < len; i++) {
        if(str[i] == '0') zero++;
        else one++;
    }
    if(zero != one) {
        printf("1\n%s\n", str);
    } else {
        printf("2\n%c %s\n", str[0], str+1);
    }
    return 0;
}