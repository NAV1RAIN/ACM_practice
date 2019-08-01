#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1 << 18;
typedef long long ll;

//add数组为延迟标记数组
//sum保存线段树的数组
//sum[i]表示编号为i的区间所对应的区间和
//初始化，sum，add都为0既可
ll sum[N], add[N];
//将标记移至下一层
void pushDown(int i, int lft, int rht) {
    if(add[i]){ //如果存在标记就向下更新
        //将上一层的标记移至下一层
        //i<<1 等价于 i*2
        //i<<1|1 等价于 i*2+1
        add[i<<1] = add[i];
        add[i<<1|1] = add[i];
        //(lft+rht)>>1等价于(lft+rht)/2
        int mid = (lft+rht)>>1;
        sum[i<<1] = add[i]*(mid-lft+1);
        sum[i<<1|1] = add[i]*(rht-mid);
        add[i] = 0; //清除本层标记
    }
}
//对区间[qft, qrht]同时加addval
//i为区间编号，[lft, rht]为编号i对应的区间
void update(int i, int lft, int rht, int qlft, int qrht, int addval) {
    if(qlft > rht || qrht < lft) return ;
    if(qlft <= lft && qrht >= rht){
        //找到对应区间，直接更新这个区间，不往下更新
        sum[i] = addval*(rht-lft+1); 
        //设置延迟更新标记
        add[i] = addval;   
    }
    else{
        //向下一层更新
        pushDown(i, lft, rht);
        int mid = (lft + rht) >> 1;
        update(i<<1, lft, mid, qlft, qrht, addval);
        update(i<<1|1, mid+1, rht, qlft, qrht, addval);
        sum[i] = sum[i<<1] + sum[i<<1|1];
    }
}
//查询区间[qft, qrht]的和
//i,lft, rht解释同update。
ll query(int i, int lft, int rht, int qlft, int qrht) {
    if(qlft > rht || qrht < lft) return 0;
    if(qlft <= lft && qrht >= rht) return sum[i];
    //向下一层更新
    pushDown(i, lft, rht);
    int mid = (lft + rht) >> 1;
    return query(i<<1, lft, mid, qlft, qrht) + query(i<<1|1, mid+1, rht, qlft, qrht);
}

int main() {
  // freopen("RAW\\in.txt", "r", stdin);
  // freopen("RAW\\out.txt", "w", stdout);
  int _;
  scanf("%d", &_);
  int n, q;
  int x, y, z;
  for (int i = 1; i <= _; i++) {
    scanf("%d%d", &n, &q);
    for (int j = 1; j <= n; j++) {
      update(1, 1, n, j, j, 1);
    }
    while (q--) {
      scanf("%d%d%d", &x, &y, &z);
      update(1, 1, n, x, y, z);
    }
    printf("Case %d: The total value of the hook is %d.\n", i, query(1, 1, n, 1, n));
  }
  return 0;
}