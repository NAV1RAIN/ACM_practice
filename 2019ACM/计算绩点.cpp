#include <iostream>
#include<stdio.h>
#include<string.h>
#include<map>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
static char x[50],y[50];
int main()
{
    double sum=0,maxd=0;
    double a,b;
    freopen("in.txt","r",stdin);
    while(cin>>x>>x>>x>>x>>x>>a>>y>>b>>y>>y>>y>>y)
    {
        if(x[0]>='0'&&x[0]<='9')
        {
//            int c=atoi(x);
//            if(c<60)continue;
            sum+=a;
            maxd+=a*b;
            //cout<<x<<' '<<a*b<<endl;
        }
        else
        {
            sum+=a;
            maxd+=a*b;
            //cout<<x<<' '<<a*b<<endl;
        }
    }
    maxd/=sum;
    cout<<maxd<<endl;
}
