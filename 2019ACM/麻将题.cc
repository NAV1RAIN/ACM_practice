#include <bits/stdc++.h>
using namespace std;
map<string, int> ss;
int main() {
    // freopen("RAW/in", "r", stdin);
    // freopen("RAW/out", "w", stdout);
    ss["234"] = 0;
    ss["243"] = ss["324"] = ss["423"] = ss["342"] = 1;
    ss["432"] = 2;
    int arr[10];
    while (scanf("%d", &arr[0]) != EOF) {
        for (int i = 1; i < 4; i++) {
            scanf("%d", &arr[i]);
        }
        int jl = 0;
        for (int i = 0; i < 4; i++) {
            if (arr[i] == 1) {
                jl = i;
                break;
            }
        }
        string temp = "";
        for (int i = 1; i < 4; i++) {
            temp.push_back('0' + arr[(i + jl) % 4]);
        }
        printf("%d\n", ss[temp]);
    }
    return 0;
}