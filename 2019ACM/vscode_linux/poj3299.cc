#include <cstdio>
#include <cmath>
using namespace std;
const double e = 2.718281828;

int main() {
    // freopen("RAW/in", "r", stdin);
    // freopen("RAW/out", "w", stdout);
    double t, d, h;
    char temp[3];
    while(scanf("%s", temp) != EOF) {
        t = d = h = -1;
        if(temp[0] == 'E') break;
        else if(temp[0] == 'T') scanf("%lf", &t);
        else if(temp[0] == 'D') scanf("%lf", &d);
        else if(temp[0] == 'H') scanf("%lf", &h);
        scanf("%s", temp);
        if(temp[0] == 'T') scanf("%lf", &t);
        else if(temp[0] == 'D') scanf("%lf", &d);
        else if(temp[0] == 'H') scanf("%lf", &h);

        if(d == -1) {
            double H = h-t;
            double E = H/0.5555+10.0;
            double t1 = 1/273.16-(log(E/6.11)/(log(e)*5417.7530));
            d = 1/t1-273.16;
        } else if(t == -1) {
            double E = 6.11*pow(e, 5417.7530*((1/273.16)-(1/(d+273.16))));
            double H = 0.5555*(E-10.0);
            t = h - H;
        } else if(h == -1) {
            double E = 6.11*pow(e, 5417.7530*((1/273.16)-(1/(d+273.16))));
            double H = 0.5555*(E-10.0);
            h = t + H;
        }

        printf("T %.1f D %.1f H %.1f\n", t, d, h);
    }
    return 0;
}