#include <bits/stdc++.h>
using namespace std;
const int SIZE = 1e5+5;
struct Node {
    int a, b, c;
}node[SIZE];
vector<Node> pl;
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        node[i].a = a, node[i].b = b, node[i].c = c;
    }
    int jl = 0;
    for(int i = 0; i < n-1; i++) {
        set<int> ss;
        ss.insert(node[i].a);
        ss.insert(node[i].b);
        ss.insert(node[i].c);
        ss.insert(node[i+1].a);
        ss.insert(node[i+1].b);
        ss.insert(node[i+1].c);
        int sLen = ss.size();
        if(sLen > 4) jl = i+1;
    }
    for(int i = jl; i < n; i++) {
        pl.push_back(node[i]);
    }
    for(int i = 0; i < jl; i++) {
        pl.push_back(node[i]);
    }
    return 0;
}