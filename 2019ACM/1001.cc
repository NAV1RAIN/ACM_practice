#include <bits/stdc++.h>
using namespace std;
#define N 100005
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
string str1, str2, str3, str4;
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
    // ios::sync_with_stdio(false);
    freopen("RAW/in", "r", stdin);
    freopen("RAW/out", "w", stdout);
    cin >> Tc;
    while (Tc--) {
        str1 = read();
        str2 = read();
        str3 = read();
        int jl1, jl2, jl3;
        jl1 = jl2 = jl3 = 0;
        for (int ii = str1.size() - 1; ii >= 0; ii--) {
            if (str1[ii] != '0')
                break;
            jl1++;
        }
        str1.erase(str1.size()-jl1, jl1);
        for (int jj = str2.size() - 1; jj >= 0; jj--) {
            if (str2[jj] != '0')
                break;
            jl2++;
        }
        str2.erase(str2.size()-jl2, jl2);
        for (int kk = str3.size() - 1; kk >= 0; kk--) {
            if (str3[kk] != '0')
                break;
            jl3++;
        }
        str3.erase(str3.size()-jl3, jl3);
        int jj = max(max(jl1, jl2), jl3);
        i = str1.size() - 1;
        j = str2.size() - 1;
        k = str3.size() - 1;
        cout << str1 << endl;
        cout << str2 << endl;
        cout << str3 << endl;
        cnta = str2.size() - j + str2.size() - k;
        cntb = str2.size() - k + str1.size() - i;
        cntc = str1.size() - i + str2.size() - j;
        str1 = str1.substr(0, i + 1);
        str2 = str2.substr(0, j + 1);
        str3 = str3.substr(0, k + 1);
        string d = add(str1, str2);
        for (i = d.size() - 1; i >= 0; i--)
            if (d[i] != '0')
                break;
        if (d.substr(0, i + 1) == str3) {
            int ep = min(cnta, min(cntb, cntc + (int)d.size() - 1 - i));
            cout << jj-jl1+cnta - ep << " " << jj-jl2+cntb - ep << " " << jj-jl3+cntc + d.size() - 1 - i - ep << '\n';
            continue;
        }
        for (i = str1.size() - 1, j = str2.size() - 1; i >= 0 && j >= 0; i--, j--)
            if (str1[i] != str3[j])
                break;
        int pq = 0;
        for (; str3[j] == '0'; j--, pq++)
            ;
        if (add(str1.substr(0, i + 1), str2) == str3.substr(0, j + 1)) {
            int ep = min(cnta, min(cntc, cntb + (int)str1.size() - 1 - i + pq));
            cout << jj-jl1+cnta - ep << " " << jj-jl2+cntb + str1.size() - 1 - i + pq - ep << " " << jj-jl3+cntc - ep << '\n';
            continue;
        }
        for (i = str2.size() - 1, j = str2.size() - 1; i >= 0 && j >= 0; i--, j--)
            if (str2[i] != str3[j])
                break;
        int qp = 0;
        for (; str3[j] == '0'; j--, qp++)
            ;
        if (add(str2.substr(0, i + 1), str1) == str3.substr(0, j + 1)) {
            int ep = min(cnta + (int)str2.size() - 1 - i + qp, min(cntb, cntc));
            cout << jj-jl1+cnta + str2.size() - 1 - i + qp - ep << " " << jj-jl2+cntb - ep << " " << jj-jl3+cntc - ep << '\n';
            continue;
        }

        for (i = str1.size() - 1, j = str2.size() - 1; i >= 0 && j >= 0; i--, j--)
            if (str1[i] != str3[j])
                break;
        //int pq=0;
        //for(;str3[j]=='0';j--,pq++);
        if (add(str1.substr(0, i + 1), str2) == str3.substr(0, j + 1)) {
            int ep = min(cnta, min(cntb + (int)str1.size() - 1 - i, cntc));
            cout << jj-jl1+cnta - ep << " " << jj-jl2+cntb + str1.size() - 1 - i - ep << " " << jj-jl3+cntc - ep << '\n';
            continue;
        }
        for (i = str2.size() - 1, j = str2.size() - 1; i >= 0 && j >= 0; i--, j--)
            if (str2[i] != str3[j])
                break;
        //int qp=0;
        //for(;str3[j]=='0';j--,qp++);
        if (add(str2.substr(0, i + 1), str1) == str3.substr(0, j + 1)) {
            int ep = min(cnta + (int)str2.size() - 1 - i, min(cntb, cntc));
            cout << jj-jl1+cnta + str2.size() - 1 - i - ep << " " << jj-jl2+cntb - ep << " " << jj-jl3+cntc - ep << '\n';
            continue;
        }

        cout << -1 << '\n';
    }

    return 0;
}