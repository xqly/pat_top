//
// Created by 肖龙 on 2020/7/12.
//
/*
 * 网络流最大流模板题，地点字符串可以用map映射一下
 */
#include <iostream>
#include <queue>
#include <climits>
#include <cstring>
#include <map>
#include <cstdio>

using namespace std;
#define ll long long int
const int maxn = 5500;

map<string,int> m1;
int ge;

ll fir[maxn],nex[maxn*2],w[maxn*2],l[maxn*2],anss;

void add_e(int u,int v,ll liu){
    w[anss]=v;
    l[anss]=liu;
    nex[anss]=fir[u];
    fir[u]=anss;
    anss++;
    w[anss]=u;
    l[anss]=0;
    nex[anss]=fir[v];
    fir[v]=anss;
    anss++;
}
ll n,m,s,t;
void init(){
    string s1,s2;
    memset(fir,-1,sizeof(fir));
    cin>>s1;
    m1[s1]=++ge;
    s=ge;
    cin>>s1;
    ge++;
    m1[s1]=ge;
    t=ge;
    cin>>m;
    int w;
    for(int i=1;i<=m;i++){
        cin>>s1>>s2>>w;
        if(m1[s1]==0){
            ge++;
            m1[s1]=ge;
        }
        if(m1[s2]==0){
            ge++;
            m1[s2]=ge;
        }
        add_e(m1[s1],m1[s2],w);
    }
}

ll pre[maxn],val[maxn],book[maxn];
queue<int> q1;
int bfs(int st,int en){
    while(!q1.empty()){
        q1.pop();
    }
    memset(book,0,sizeof(book));
    val[st]=INT_MAX;
    book[st]=1;
    q1.push(st);
    int dd;
    while(!q1.empty()){
        dd=q1.front();
        q1.pop();
        for(int i=fir[dd];i!=-1;i=nex[i]){
            if(book[w[i]]||l[i]==0)continue;
            book[w[i]]=1;
            pre[w[i]]=i;
            val[w[i]]=min(val[dd],l[i]);
            if(w[i]==en) return 1;
            q1.push(w[i]);
        }
    }
    return 0;
}

ll EK(int st,int en){
    ll answ=0;
    int p;
    while(bfs(st,en)){
        answ+=val[en];
        p = en;
        while(p!=st){
            l[pre[p]]-=val[en];
            l[pre[p]^1]+=val[en];
            p=w[pre[p]^1];
        }
    }
    return answ;
}

int main(){
    init();
    cout<<EK(s,t)<<endl;
    return 0;
}