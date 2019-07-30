// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     // freopen("RAW/in", "r", stdin);
//     // freopen("RAW/out", "w", stdout);
//     int T, n, k;
//     scanf("%d", &T);
//     while(T--) {
//         scanf("%d%d", &n, &k);
//         if(n == 0) {
//             printf("Bob\n");
//         } else if((n > 0 && n < 3) || n == k || (k == 3 && n%3 == 0)) {
//             printf("Alice\n");
//         } else if(k < n) {
//             if(n%k%3 == 0 || (n%(k+1) == 0 && (n+1)%3 != 0) || (n%(k+2) == 0)) {
//                 printf("Bob\n");
//             } else {
//                 printf("Alice\n");
//             }
//         } else {
//             if(n % 3 == 0) printf("Bob\n");
//             else printf("Alice\n");
//         }
//     }
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
const int maxn =2e2+100;
int main()
{
	std::ios::sync_with_stdio(false);
	int d[maxn];
	d[0] = 1;
	for(int i = 0;i<maxn;i++) d[i] = 1;
	for(int i = 0;i<maxn-100;i++){
        if(d[i]==1) d[i+1]=d[i+2]=d[i+15]=0;
        cout<<d[i];
	}
	return 0;
}
