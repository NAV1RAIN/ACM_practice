#include <bits/stdc++.h>
using namespace std;
const int SIZE = 2e5+5;
struct Node {
    int id;
    double x, y, z;
    bool operator < (const Node& t) {
        if(this->x == t.x) {
            if(this->y == t.y) return this->z < t.z;
            return this->y < t.y;
        } else {
            return this->x < t.x;
        }
        return false;
    }
} node[SIZE];
bool jl[SIZE];
int main() {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int len = 0;
    for(int i = 1; i <= n; i++) {
        cin >> node[i].x >> node[i].y >> node[i].z;
        node[i].id = i;
    }
    sort(node + 1, node + n + 1);
    int hh = 1;
    for(int i = 2; i <= n; i++) {
        if(jl[i]) continue;
        if(hh && node[i].x == node[hh].x && node[i].y == node[hh].y) {
            jl[i] = jl[hh] = true;
            cout << node[i].id << " " << node[hh].id << '\n';
            hh = 0;
        } else {
            hh = i;
        }
    }
    hh = 1;
    while(jl[hh]) hh++;
    for(int i = hh+1; i <= n; i++) {
        if(jl[i]) continue;
        if(hh && node[i].x == node[hh].x) {
            jl[i] = jl[hh] = true;
            cout << node[i].id << " " << node[hh].id << '\n';
            hh = 0;
        } else {
            hh = i;
        }
    }
    hh = 1;
    while(jl[hh]) hh++;
    for(int i = hh+1; i <= n; i++) {
        if(jl[i]) continue;
        if(hh) {
            jl[i] = jl[hh] = true;
            cout << node[i].id << " " << node[hh].id << '\n';
            hh = 0;
        } else {
            hh = i;
        }
    }
    return 0;
}