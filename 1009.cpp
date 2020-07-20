//
// Created by 肖龙 on 2020/7/20.
//
/*
 * 三维偏序，但是也可以用两次树状数组即可
 * 第一次树状数组求以i结尾的二维逆序对个数
 * 第二次求总共，但是添加的价值是以第一次的二维逆序对的个数为价值
 */

#include <iostream>
#include <cstring>
#define LB(X) X&-X
using namespace std;

const long long int maxn = 1e5+100;
long long int n,a[maxn];

void add(long long int t[],long long int x,long long int y){
    for(long long int i=x;i<=n;i+=LB(i)){
        t[i]+=y;
    }
}

long long int sum(long long int t[],long long int x){
    long long int all=0;
    if(x<=0) return 0;
    for(long long int i=x;i;i-=LB(i)){
        all+=t[i];
    }
    return all;
}

long long int tree[maxn];
long long int ans[maxn];
long long int anss[maxn];
int main(){
    cin>>n;
    long long int answ=0;
    for(long long int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(long long int i=1;i<=n;i++){
        ans[i]=(i-1)-sum(tree,a[i]);
        add(tree,a[i],1);
    }
    memset(tree,0,sizeof(tree));
    long long int bb=0;
    for(long long int i=1;i<=n;i++){
        anss[i]=answ-sum(tree,a[i]);
        bb+=anss[i];
        add(tree,a[i],ans[i]);
        answ+=ans[i];
    }
    cout<<bb<<endl;
    return 0;
}