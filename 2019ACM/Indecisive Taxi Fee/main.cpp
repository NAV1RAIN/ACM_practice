#include <bits/stdc++.h>
using namespace std;

int n,x,sum=0,vis[300005];

struct node
{
    int l=300005,h=-1;

}a[300005];


int main()
{
    //freopen("in.txt","r",stdin);
    set<int> se;
    vector<int> ve;

    memset(vis,0,sizeof(vis));

    cin>>n;

    for(int i=1;i<=n;i++){

        cin>>x;
        cout<<x<<endl;
        cout<<se.count(x)<<endl;
        if(se.count(x)!=0){
            se.insert(x);

            ve.push_back(x);
            //cout<<ve[0]<<endl;
            sum++;
        }

        a[i].l=min(a[i].l,x);
        a[i].h=max(a[i].h,x);

        vis[a[i].l]=a[i].h;

    }

//    int xi[300005],da[300005];
    for(int i=0;i<sum;i++){
            //cout<<ve[i]<<endl;
       // xi[i]=a[ve[i]].l;
        //da[i]=a[ve[i]].h;
    }/*
    sort(xi,xi+sum);
    sort(da,da+sum);


    if(vis[xi[0]]!=da[sum-1]){
        cout<<da[sum-1]-xi[0]<<endl;
    }
    else{
        cout<<max(da[sum-1]-xi[0],da[sum-2]-xi[1])<<endl;
    }*/

    return 0;
}
