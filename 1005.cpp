//
// Created by 肖龙 on 2020/7/13.
//

/*
 * 可以直接用map来统计一下所有长度为N的字符串的出现次数。28分
 *
 */

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;

string s;
int n,ge;
map<string,int> m1;
struct node{
    int x;
    int st;
}a[1000010];

int book[500];
node b[500];

int cmp(node x,node y){
    return x.x>y.x;
}

void init(){
    for(int i=0;i<s.size();i++){
        b[s[i]].x++;
        b[s[i]].st=s[i];
//        cout<<s[i]<<" "<<b[s[i]].st<<" "<<b[s[i]].x<<endl;
    }
    sort(b+1,b+1+400,cmp);
    for(int i=1;i<=10;i++){
        if(b[i].x==0)break;
        book[b[i].st]=1;
//        cout<<b[i].x<<" "<<b[i].st<<endl;
    }
}


int main(){
    cin>>n;
    getchar();
    getline(cin,s);
    int dd;
    init();
    for(int i=0;i<s.size()-n+1;i++){
        if(book[s[i]]==0)continue;
        dd=m1[s.substr(i,n)];
        if(dd==0){
            ge++;
            m1[s.substr(i,n)]=ge;
            dd=ge;
            a[dd].st=i;
            a[dd].x=0;
        }
        a[dd].x++;
    }
    int who=0;
    for(int i=1;i<=ge;i++){
        if(a[i].x>who){
            who=i;
        }
        else if(a[i].x==who&&s.substr(a[who].st,n)>s.substr(a[i].st,n)){
            who=i;
        }
    }
    cout<<s.substr(a[who].st,n)<<" "<<a[who].x<<endl;
    return 0;
}