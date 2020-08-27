#include "bits/stdc++.h"
using namespace std;
 
vector<int> adjl[100005];
int siz[100005],ans=0;
 
void dfs(int node,int prev){
  for(int x=0;x<adjl[node].size();x++){
    if(adjl[node][x]==prev)continue;
    dfs(adjl[node][x],node);
    siz[node]+=siz[adjl[node][x]];
  }
  siz[node]%=2;
  if(siz[node]==0){//number of even connected components...
    ans++;
  }
}
 
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,a,b;
    cin>>n;
    if((n%2)==1){
      cout<<"-1";
      return 0;
    }
    for(int x=1;x<n;x++){
      cin>>a>>b;
      adjl[a].push_back(b);
      adjl[b].push_back(a);
      siz[x]=1;
    }
    siz[n]=1;
    dfs(1,-1);
    cout<<ans-1;
    return 0;
}