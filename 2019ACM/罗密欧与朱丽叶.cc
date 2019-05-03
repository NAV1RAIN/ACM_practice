#include <cstdio>
using namespace std;
int minn = 0x3f3f3f3f;
int cf;
int n, m, k;
int dr[8] = {0, 0, -1, 1, -1, -1, 1, 1};
int dc[8] = {-1, 1, 0, 0, -1, 1, -1, 1};
int qdr, qdc, zdr, zdc;
int fj[100][100];
int ans[100][100];
void dfs(int r, int c, int fx, int num) {
	if(num > minn) return;
	if(r == zdr && c == zdc) {
		if(minn == num) cf++;
		else if(minn > num) {
			cf = 1;
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < m; j++) {
					ans[i][j] = fj[i][j];
				}
			}
		}
		return ;
	}
	
	for(int i = 0; i < 8; i++) {
		int tr = r+dr[i], tc = c+dc[i];
		if(tr < 0 || tc < 0 || tr >= n || tc >= m) continue;
		if(fx == -1) ;
		else if(dr[fx]*-1 == dr[i] && dc[fx]*-1 == dc[i]) continue;
		if(fx != i && fx != -1) num++;
		fj[tr][tc] = fj[r][c]+1;
		dfs(tr, tc, i, num);
		fj[tr][tc] = 0;
	}

	return ;
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < k; i++) {
		int tx, ty;
		scanf("%d%d", &tx, &ty);
		fj[tx][ty] = -1;
	}
	scanf("%d%d%d%d", &qdr, &qdc, &zdr, &zdc);
	qdr--, qdc--, zdr--, zdc--;
	fj[qdr][qdc] = 1, fj[zdr][zdc] = n*m-k;
	dfs(qdr, qdc, -1, 0);
	
	return 0;
}
