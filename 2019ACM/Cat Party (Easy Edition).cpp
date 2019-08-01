#include <bits/stdc++.h>
using namespace std;
const int SIZE = (int)1e5+5;
int arr[SIZE];
int num[20];
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }
    int ans = 2;
    for(int i = 1; i <= n; i++) {
        num[arr[i]]++;
        int minn = 0x3f3f3f3f;
        bool ok = true;
        int bt = 0;
        for(int j = 1; j <= 10; j++) {
            if(num[j] != 0) minn = min(minn, num[j]);
        }
        for(int j = 1; j <= 10; j++) {
            if(num[j] > 0 && minn != num[j]) {
                bt++;
                if(num[j]-minn > 1) ok = false;
            }
        }
        if(ok && bt == 1) {
            ans = i;
        } else if(ok && bt == 0 && (minn == 1 || i < n)) ans = i+1;
        if(minn == 1 && bt != 0) {
            for(int j = 1; j <= 10; j++) {
                minn = max(minn, num[j]);
            }
            bt = 0;
            for(int j = 1; j <= 10; j++) {
                if(num[j] > 0 && num[j] != minn) bt++;
            }
            if(bt == 1) {
                ans = i;
            }
        }
    }
    if(ans > n) ans = n;
    printf("%d\n", ans);
    return 0;
}
