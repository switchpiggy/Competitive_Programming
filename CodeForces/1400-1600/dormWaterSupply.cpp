#include <bits/stdc++.h>
using namespace std;
 
#define sz(x) (int)x.size()
 
int n,p;
int indg[1010],outdg[1010];
pair<int,int> nxt[1010];
int u,v,w;
vector<pair<int,pair<int,int> > > ans;
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
#endif
    scanf("%d %d",&n,&p);
    for(int i=0;i<p;i++){
        scanf("%d %d %d",&u,&v,&w);
        nxt[u]={v,w};
        outdg[u]++,indg[v]++;
    }
    for(int i=1;i<=n;i++){
        if(indg[i]==0&&outdg[i]==1){
            int cur=i,d=100000000;
            while(outdg[cur]){
                d=min(d,nxt[cur].second);
                cur=nxt[cur].first;
            }
            ans.push_back({i,{cur,d}});
        }
    }
    cout<<sz(ans)<<endl;
    for(int i=0;i<sz(ans);i++)
        printf("%d %d %d\n",ans[i].first,ans[i].second.first,ans[i].second.second);
}