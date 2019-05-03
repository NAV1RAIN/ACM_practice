#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int SIZE = 2005;
struct node {
	int num, jl, xb;
	node(int _num = 0, int _jl = 0, int _xb = 0) : num(_num), jl(_jl), xb(_xb) {}
	bool operator < (const node& a) const {
		if(jl != a.jl) return jl > a.jl;
		else return num < a.num;
	}
} ws[SIZE];
bool cmp(const node& a, const node& b) {
	return a.num > b.num;
}
int d[SIZE];
int hh[SIZE][SIZE];
priority_queue<node> q;
vector<node> temp;
int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int m, n, w, h;
	scanf("%d%d%d%d", &m, &n, &w, &h);
	for(int i = 0; i < m; i++) {
		int tt;
		scanf("%d", &tt);
		ws[i] = node(tt/w, -w-h, i);
		q.push(ws[i]);
	}
	for(int i = 1; i <= n; i++) {
		scanf("%d", &d[i]);
	}
	bool flag = true;
	for(int i = 1; i <= n && flag; i++) {
		while(d[i] > 0) {
			temp.clear();
			int xb = -1;
			node tt = q.top();
			q.pop();
			while(q.size() && q.top().jl <= i) {
				temp.push_back(tt);
				tt = q.top();
				q.pop();
			}
			if(tt.jl > i) {
				flag = false;
				break;
			}
			temp.push_back(tt);
			sort(temp.begin(), temp.end(), cmp);
			tt = temp[0];
			hh[tt.xb][++hh[tt.xb][0]] = i;
			tt.jl = i+w+h;
			//printf("%d %d\n", i, tt.num);
			tt.num--;
			//printf("%d %d\n", tt.num, tt.xb);
			if(tt.num > 0) q.push(tt);
			int len = temp.size();
			for(int j = 1; j < len; j++) {
				q.push(temp[j]);
			}
			for(int j = 0; j < w; j++) {
				d[i+j]--;
			}
		}
	}
	if(flag) {
		printf("1\n");
		for(int i = 0; i < m; i++) {
			printf("%d", hh[i][1]);
			for(int j = 2; j <= hh[i][0]; j++) {
				printf(" %d", hh[i][j]);
			}
			printf("\n");
		}
	} else {
		printf("-1\n");
	}
	return 0;
}
