#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n,m,k,l,i,j,a,b,d[3005],res[3005];
vector<int> v[3002];
 
 
int dfs(int q,int w){
    d[q]=1;
    for(int i1=0;i1<v[q].size();i1++){
        if(v[q][i1]==w) continue;
        if(d[v[q][i1]]==1) 
        {
            if(k==0) k=v[q][i1];
            return 0;
        }
        dfs(v[q][i1],q);
        if(q==k) l=1;
        if(d[v[q][i1]]==1 && k!=0 && l==0) return 0;
    }
    if(l==1 || k==0) d[q]=0;
    return 0;
}
 
 
int dfs1(int q,int p,int w){
    for(int i1=0;i1<v[q].size();i1++){
        a=v[q][i1];
        if(a==w) continue;
        if(d[a]==1) continue;
        res[a]=p;
        dfs1(a,p+1,q);
    }
    return 0;
}
 
main(){
 
cin>>n;
 
for(i=0;i<n;i++){
cin>>a>>b;
    v[a].push_back(b);
    v[b].push_back(a);
}
 
dfs(1,0);
 
 
for(i=1;i<=n;i++){
    if(d[i]==1) {dfs1(i,1,0);}
}
 
for(i=1;i<=n;i++)
    cout<<res[i]<<" ";
 
}
