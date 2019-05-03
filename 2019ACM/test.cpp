#include <cstdio>
using namespace std;
const int SIZE = 2005;
struct node {
	int num, jl;
	node(int _num = 0, int _jl = 0) : num(_num), jl(_jl) {}
} ws[SIZE];
int d[SIZE];
int hh[SIZE][SIZE];
vector<node> temp;
bool cmp(const node& a, const node& b) {
	if(a.jl != b.jl) return a.jl > b.jl;
	else return a.num > b.num;
}
int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int m, n, w, h;
	scanf("%d%d%d%d", &m, &n, &w, &h);
	for(int i = 0; i < m; i++) {
		int tt;
		scanf("%d", &tt);
		ws[i] = node(tt/w, -w-h);
	}
	for(int i = 1; i <= n; i++) {
		scanf("%d", &d[i]);
	}
	bool flag = true;
	for(int i = 1; i <= n; i++) {
		int xb = -1;
		for(int j = 0; j < m; j++) {
			if(ws[j].num > 0 && ws[j].jl+w+h <= i) {
				temp.push_back(ws[j]);
			}
		}
		sort(temp.begin(), temp.end(), cmp);
		int len = temp.size();
		if(len < d[i]) {
			flag = false;
			break;
		}
		
	}
	for(int i = 1; i <= n; i++) {
		while(d[i] > 0) {
			int xb = -1;
			for(int j = 0; j < m; j++) {
				if(ws[j].num > 0 && ws[j].jl+w+h <= i) {
					xb = j;
					break;
				}
			}
			if(xb == -1) {
				flag = false;
		//		printf("-1\n");
				break;
			}
			for(int j = xb+1; j < m; j++) {
				if(ws[j].num > 0 && ws[j].num > ws[xb].num && ws[j].jl+w+h <= i) {
					xb = j;
				}
			}
			hh[xb][++hh[xb][0]] = i;
			ws[xb].jl = i;
			ws[xb].num--;
	//		printf("%d %d\n", i, xb);
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
