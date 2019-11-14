#include <bits/stdc++.h>
using namespace std;
const int SIZE = 1e5+5;
double w[SIZE];
int main() {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    int T;
    scanf("%d", &T);
    int n;
    double k;
    double sum;
    while(T--) {
        sum = 0;
        scanf("%d%lf", &n, &k);
        for(int i = 0; i < n; i++) {
            scanf("%lf", &w[i]);
            sum += w[i];
        }
        for(int i = 0; i < n; i++) {
            if(i != 0) printf(" ");
            printf("%.8f", w[i]+k*w[i]/sum);
        }
        printf("\n");
    }
    return 0;
}