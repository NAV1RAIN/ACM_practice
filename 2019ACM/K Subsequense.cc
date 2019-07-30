#include <stdio.h>
#include <string.h>

int array[1010];
int Max[1010];

void LIS(int k) {
    memset(Max, 0, sizeof(Max));
    for (int i = 1; i <= k; i++) {
        Max[i] = array[i];
        //和i号数据之前的数据比较
        for (int j = 1; j < i; j++) {
            if (array[i] >= array[j]) {
                if (Max[i] < Max[j] + array[i]) {
                    Max[i] = Max[j] + array[i];
                }
            }
        }
    }
}
int main() {
    freopen("RAW/in", "r", stdin);
    freopen("RAW/out", "w", stdout);
    int N, i;
    while (scanf("%d", &N) != EOF) {
        //输入数据
        for (i = 1; i <= N; i++) {
            scanf("%d", &array[i]);
        }
        LIS(N);
        //输出最大值
        int MaxValue = -1;
        for (i = 1; i <= N; i++) {
            if (MaxValue < Max[i]) {
                MaxValue = Max[i];
            }
        }
        printf("%d\n", MaxValue);
    }
    return 0;
}