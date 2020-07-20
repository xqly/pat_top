//
// Created by 肖龙 on 2020/7/20.
//
/*
tarjan 板子题，只要属于同一强连通分量，那么就Yes,反之No
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#define pb push_back
using namespace std;
const int maxn = 1e4+100;
vector<int> e[maxn];

int n,m;

int low[maxn],dfn[maxn],tim;
int who[maxn],ge;
int book[maxn];
stack<int> st;

void tarjan(int x){
    tim++;
    low[x]=dfn[x]=tim;
    book[x]=1;
    st.push(x);
    for(auto v:e[x]){
        if(dfn[v]==0){
            tarjan(v);
            low[x]=min(low[x],low[v]);
        }
        else if(book[v]){
            low[x]=min(low[x],dfn[v]);
        }
    }
    if(dfn[x]==low[x]){
        ge++;
        int node;
        do{
            node = st.top();
            st.pop();
            book[node]=0;
            who[node]=ge;
        }while(node!=x);
    }
}

int main(){
    scanf("%d%d",&n,&m);
    int aa,bb;
    for(int i=1;i<=m;i++){
//        cin>>aa>>bb;
        scanf("%d%d",&aa,&bb);
        e[aa].pb(bb);
    }
//    tarjan(1);
    for(int i=1;i<=n;i++){
        if(dfn[i]==0){
            tarjan(i);
        }
    }
//    for(int i=1;i<=n;i++){
//        cout<<low[i]<<" "<<dfn[i]<<" "<<who[i]<<endl;
//    }
//    cout<<endl;
    int k;
    cin>>k;
    for(int i=1;i<=k;i++){
//        cin>>aa>>bb;
        scanf("%d%d",&aa,&bb);
//        cout<<who[aa]<<" "<<who[bb]<<endl;
        if(who[aa]==who[bb]){
            printf("Yes\n");
        }
        else printf("No\n");
    }
    return 0;
}

/*
6 8
 1 3
 3 5
 1 2
 3 4
 5 6
 4 1
 2 4
 4 6
 0

 */