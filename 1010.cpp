//
// Created by 肖龙 on 2020/7/20.
//
/*
 * 树状数组板子题
 * 先离散化，把数字离散化到1——n
 * 后面利用树状数组统计一下即可
 */
#include <iostream>
#include <map>
#include <algorithm>
#define LB(X) X&-X
using namespace std;
const int maxn = 1e5+100;
int n;
int a[maxn],b[maxn];
int L[maxn];
map<int,int> m1;

void init(){
    for(int i=1;i<=n;i++){
        b[i]=a[i];
    }
    sort(b+1,b+1+n);
    for(int i=1;i<=n;i++){
        m1[b[i]]=i;
    }
    for(int i=1;i<=n;i++){
        a[i]=m1[a[i]];
    }
}
int tree[maxn];

void add(int x){
    for(int i=x;i<=n;i+=LB(i)){
        tree[i]++;
    }
}

int get(int y){
    int x=0;
    for(int i=y;i;i-=LB(i)){
        x+=tree[i];
    }
    return x;
}


int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    init();
    for(int i=n;i;i--){
        L[i]=get(a[i]);
        add(a[i]);
    }
    for(int i=1;i<n;i++){
        cout<<L[i]<<' ';
    }
    cout<<L[n];
    cout<<endl;
    return 0;
}