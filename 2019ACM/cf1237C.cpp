#include <bits/stdc++.h>
using namespace std;
const int SIZE = 2005;
struct Node {
    int id;
    double x, y, z;
    bool operator < (const Node& t) {
        if(this->z < t.z) return true;
        else {
            if(this-> y < t.y) return true;
            else {
                if(this-> x < t.x) return true;
            }
        }
        return false;
    }
} node[SIZE];
struct HH {
    int id1, id2;
    double jg;
    bool operator < (const HH& t) {
        return this->jg < t.jg;
    }
}hh[SIZE*SIZE];
bool jl[SIZE];
int main() {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int len = 0;
    for(int i = 0; i < n; i++) {
        cin >> node[i].x >> node[i].y >> node[i].z;
        node[i].id = i+1;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            hh[len].id1 = i, hh[len].id2 = j;
            hh[len].jg = fabs(node[i].x-node[j].x)+fabs(node[i].y-node[j].y)+fabs(node[i].z-node[j].z);
            len++;
        }
    }
    sort(hh, hh + len);
    for(int i = 0; i < len; i++) {
        if(!jl[hh[i].id1] && !jl[hh[i].id2]) {
            jl[hh[i].id1] = jl[hh[i].id2] = true;
            cout << hh[i].id1+1 << " " << hh[i].id2+1 << '\n';
        }
    }
    return 0;
}

/*#include <bits/stdc++.h>
using namespace std;
const int SIZE = 2005;
struct Node{
    int x, y, z, id;
    bool operator < (const Node& t) {
        if(this->z < t.z) return true;
        else {
            if(this-> y < t.y) return true;
            else {
                if(this-> x < t.x) return true;
            }
        }
        return false;
    }
} node[SIZE];
int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        node[i].x = x, node[i].y = y, node[i].z = z;
        node[i].id = i + 1;
    }
    sort(node, node + n);
    for(int i = 0; i < n; i++) {
        cout << node[i].id << " - " << node[i].x << node[i].y << node[i].z << '\n';
    }
    return 0;
}*/