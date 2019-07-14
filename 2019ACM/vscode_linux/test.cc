#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    freopen("RAW/out", "w", stdout);
    int arr[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    long long ans = 0;
    do {
        if(arr[0] != 1 && arr[1] != 2 && arr[2] != 3 && arr[3] != 4 && arr[4] != 5 && arr[5] != 6 && arr[6] != 7
        && arr[7] != 8 && arr[8] != 9 && arr[9] != 10 && arr[10] != 11) {
            for(int i = 0; i < 11; i++) {
                for(int j = i+1; j < 11; j++) {
                    if(arr[i] > arr[j]) {
                        ans += (arr[i]-arr[j])*(j-i);
                    }
                }
            }
        }
    } while(next_permutation(arr, arr + 11));
    printf("%lld\n", ans);
    return 0;
}