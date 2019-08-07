#include<bits/stdc++.h>
using namespace std;
int m;
int gcd(long long a, long long b)
{
     if(b==1){
         return 1;
     }
     if (a % b == 0)
     {
         return b;
     }
     return gcd(b, a % b);
}
long long zkx(long long n){

    int mm = m;
    long long ans = n + 1;
    while (mm--)
    {
        while(gcd(ans,n)!=1){
            ans++;
        }
        if(mm==0){
            break;
        }
        ans++;
    }
    return ans;
}
void init(){
    m = 100;
    long long ans = 0;
    for (long long i = 2; i <= 1e18; i++)
    {
        ans = max(ans, zkx(i) - i);
        if(i%100000==0){
            cout << ans << endl;
        }
    }
    cout << ans << endl;
}
int main(){

    int t;
    long long k;
    scanf("%d", &t);
    while(t--){
        scanf("%lld %d", &k, &m);
        long long ans = (1e18)+1000000;
        for (long long i = 1; i <= 1000; i++)
        {
            long long n = i ^ k;
            if(n==0)
                continue;
            if (zkx(n) - n == i)
            {
                ans = min(ans, n);
            }
        }
        if(ans==(1e18+1000000)){
            printf("-1\n");
        }else{
            printf("%lld\n", ans);
        }
    }
    return 0;
}