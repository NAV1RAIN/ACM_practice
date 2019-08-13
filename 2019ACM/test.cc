#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define N 300005
inline string read() {
    char ch = getchar();
    string st1 = "";
    while (!((ch >= '0') && (ch <= '9')))
        ch = getchar();
    while ((ch >= '0') && (ch <= '9'))
        st1 += ch, ch = getchar();
    return st1;
}
int Tc;
string a, b, c;
int i, j, k;
int cnta, cntb, cntc;
inline string add(string x, string y) {
    if (x.size() < y.size())
        swap(x, y);
    string gao0 = "";
    for (int i = 0; i < x.size() - y.size(); i++)
        gao0 += "0";
    y = gao0 + y;
    char z[N];
    memset(z, 0, sizeof(z));
    int g;
    for (g = 0; g < x.size(); g++) {
        z[g] = x[x.size() - 1 - g] + y[y.size() - 1 - g] - '0';
        if (g && z[g - 1] > '9')
            z[g - 1] -= 10, z[g]++;
    }
    bool ok = 0;
    int pig = x.size() - 1;
    if (z[pig] > '9') {
        z[pig] -= 10;
        z[pig + 1] = '1';
        ok = 1;
    }
    if (!ok)
        reverse(z, z + x.size());
    else
        reverse(z, z + x.size() + 1);
    return z;
}

int main() {
    freopen("RAW/in", "r", stdin);
    freopen("RAW/out", "w", stdout);
    // ios::sync_with_stdio(false);
    cin >> Tc;
    while (Tc--) {
        int jl1, jl2, jl3;
        jl1 = jl2 = jl3 = 0;
        a = read();
        b = read();
        c = read();
        for (i = a.size() - 1; i >= 0; i--) {
            if (a[i] != '0')
                break;
            jl1++;
        }
        for (j = b.size() - 1; j >= 0; j--) {
            if (b[j] != '0')
                break;
            jl2++;
        }
        for (k = c.size() - 1; k >= 0; k--) {
            if (c[k] != '0')
                break;
            jl3++;
        }
        int jj = max(max(jl1, jl2), jl3);
        a.erase(a.size() - jl1, jl1);
        b.erase(b.size() - jl2, jl2);
        c.erase(c.size() - jl3, jl3);
        i = a.size() - 1;
        j = b.size() - 1;
        k = c.size() - 1;
        cnta = b.size() - j + c.size() - k;
        cntb = c.size() - k + a.size() - i;
        cntc = a.size() - i + b.size() - j;
        a = a.substr(0, i + 1);
        b = b.substr(0, j + 1);
        c = c.substr(0, k + 1);
        string d = add(a, b);
        for (i = d.size() - 1; i >= 0; i--)
            if (d[i] != '0')
                break;
        if (d.substr(0, i + 1) == c) {
            int ep = min(cnta, min(cntb, cntc + (int)d.size() - 1 - i));
            cout << jj - jl1 + cnta - ep << " " << jj - jl2 + cntb - ep << " " << jj - jl3 + cntc + d.size() - 1 - i - ep << '\n';
            continue;
        }
        for (i = a.size() - 1, j = c.size() - 1; i >= 0 && j >= 0; i--, j--)
            if (a[i] != c[j])
                break;
        int pq = 0;
        for (; c[j] == '0'; j--, pq++)
            ;
        if (add(a.substr(0, i + 1), b) == c.substr(0, j + 1)) {
            int ep = min(cnta, min(cntc, cntb + (int)a.size() - 1 - i + pq));
            cout << jj - jl1 + cnta - ep << " " << jj - jl2 + cntb + a.size() - 1 - i + pq - ep << " " << jj - jl3 + cntc - ep << '\n';
            continue;
        }
        for (i = b.size() - 1, j = c.size() - 1; i >= 0 && j >= 0; i--, j--)
            if (b[i] != c[j])
                break;
        int qp = 0;
        for (; c[j] == '0'; j--, qp++)
            ;
        if (add(b.substr(0, i + 1), a) == c.substr(0, j + 1)) {
            int ep = min(cnta + (int)b.size() - 1 - i + qp, min(cntb, cntc));
            cout << jj - jl1 + cnta + b.size() - 1 - i + qp - ep << " " << jj - jl2 + cntb - ep << " " << jj - jl3 + cntc - ep << '\n';
            continue;
        }
        for (i = a.size() - 1, j = c.size() - 1; i >= 0 && j >= 0; i--, j--)
            if (a[i] != c[j])
                break;
        //int pq=0;
        //for(;c[j]=='0';j--,pq++);
        if (add(a.substr(0, i + 1), b) == c.substr(0, j + 1)) {
            int ep = min(cnta, min(cntb + (int)a.size() - 1 - i, cntc));
            cout << jj - jl1 + cnta - ep << " " << jj - jl2 + cntb + a.size() - 1 - i - ep << " " << jj - jl3 + cntc - ep << '\n';
            continue;
        }
        for (i = b.size() - 1, j = c.size() - 1; i >= 0 && j >= 0; i--, j--)
            if (b[i] != c[j])
                break;
        //int qp=0;
        //for(;c[j]=='0';j--,qp++);
        if (add(b.substr(0, i + 1), a) == c.substr(0, j + 1)) {
            int ep = min(cnta + (int)b.size() - 1 - i, min(cntb, cntc));
            cout << jj - jl1 + cnta + b.size() - 1 - i - ep << " " << jj - jl2 + cntb - ep << " " << jj - jl3 + cntc - ep << '\n';
            continue;
        }

        cout << -1 << '\n';
    }

    return 0;
}