#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    double cheng = 0;
    double zxf = 0;
    double cj, xf, c;
    int js = 0;
    while(scanf("%lf%lf", &cj, &xf) != EOF) {
        c = cj*xf;
        zxf += xf;
        cheng += c;
        js++;
    }
    cout << zxf << '\n' << cheng/zxf << '\n' << js << '\n';
    return 0;
}
