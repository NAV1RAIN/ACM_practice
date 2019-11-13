#include <bits/stdc++.h>
using namespace std;
const int SIZE = 105;
int arr[SIZE];
int main() {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    int n;
    scanf("%d", &n);
    bool flag = false;
    for(int i = n; i >= 0; i--) {
        scanf("%d", &arr[i]);
        // printf("%d\n", arr[i]);
        if(arr[i] != 0) {
            if(!flag) {
                if(arr[i] > 1) printf("%d", arr[i]);
                else if(arr[i] < -1) printf("%d", arr[i]);
                else if(arr[i] == -1) printf("-");
                flag = true;
            } else {
                if(arr[i] > 1) printf("+%d", arr[i]);
                else if(arr[i] < -1) printf("%d", arr[i]);
                else if(arr[i] == 1) printf("+");
                else if(arr[i] == -1) printf("-");
            }
            if(i == 1) printf("x");
            else if(i > 1) printf("x^%d", i);
            else if(abs(arr[i]) == 1) printf("1");
        }
    }
    printf("\n");
    return 0;
}