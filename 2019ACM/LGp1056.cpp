#include <bits/stdc++.h>
using namespace std;
const int SIZE =1e4+5;
set<int> a, b;
int aa[SIZE], bb[SIZE];
struct Node {
    int num, id;
};
vector<Node> arrA, arrB;
bool cmp(const Node& a, const Node& b) {
    return a.num > b.num;
}
vector<int> ansA, ansB;
int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    int m, n, k, l, d;
    scanf("%d%d%d%d%d", &m, &n, &k, &l, &d);
    for(int i = 0; i < d; i++) {
        int x1, x2, y1, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        if(x1 == x2) {
            b.insert(min(y1, y2));
            bb[min(y1, y2)]++;
        }
        else if(y1 == y2) {
            a.insert(min(x1, x2));
            aa[min(x1, x2)]++;
        }
    }
    for(set<int>::iterator it = a.begin(); it != a.end(); it++) {
        Node temp;
        temp.id = *it;
        temp.num = aa[temp.id];
        arrA.push_back(temp);
    }
    for(set<int>::iterator it = b.begin(); it != b.end(); it++) {
        Node temp;
        temp.id = *it;
        temp.num = aa[temp.id];
        arrB.push_back(temp);
    }
    sort(arrA.begin(), arrA.end(), cmp);
    sort(arrB.begin(), arrB.end(), cmp);
    for(int i = 0; i < k; i++) {
        ansA.push_back(arrA[i].id);
    }
    for(int i = 0; i < l; i++) {
        ansB.push_back(arrB[i].id);
    }
    sort(ansA.begin(), ansA.end());
    sort(ansB.begin(), ansB.end());
    for(int i = 0; i < k; i++) {
        if(i != 0) printf(" ");
        printf("%d", ansA[i]);
    }
    printf("\n");
    for(int i = 0; i < l; i++) {
        if(i != 0) printf(" ");
        printf("%d", ansB[i]);
    }
    printf("\n");
    return 0;
}