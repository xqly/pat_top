//
// Created by 肖龙 on 2020/7/12.
//
/*
 * dp[i][j] 第i个物体和第j分钟，
 * ？？？？？？？？？但是我不清楚为啥得按照结束时间来排序，而不是最晚开始时间。？？？？？？？？？
 */
#include<iostream>
#include <algorithm>
using namespace std;
#define ll long long int
ll n;
struct node{
    ll x,y,z;
    ll near;
}a[55];

ll cmp(node x,node y){
//    if(x.near==y.near){
//        return x.y<y.y;
//    }
    return x.z<y.z;
}

ll answ;

void dfs(ll x,ll y,ll z){// who time cost
    answ=max(answ,z);
    if(x>n) return ;
    if(a[x].near>=y){
        dfs(x+1,y+a[x].y,z+a[x].x);
    }
    dfs(x+1,y,z);
}

ll dp[55][100010];

int main(){
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y>>a[i].z;
        a[i].near=a[i].z-a[i].y;
    }
    sort(a+1,a+1+n,cmp);
    ll answ=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=100000;j++){
            dp[i][j]=dp[i-1][j];
            if(j<a[i].y||j>a[i].z)continue;
            dp[i][j]=max(dp[i][j],dp[i-1][j-a[i].y]+a[i].x);
            answ=max(answ,dp[i][j]);
        }
    }
    cout<<answ<<endl;
    return 0;
}