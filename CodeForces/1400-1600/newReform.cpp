#include<bits/stdc++.h>
using namespace std;
const int size = 1e6 + 9;
vector < int > Adj[size];
bool vis[size];
int cnt = 0,edges=0;
void DFS(int node){
	vis[node]=1;
	cnt++;
	edges += Adj[node].size();
	for(auto it : Adj[node]){
		if(!vis[it])
			DFS(it);
	}
}
int main(){
	int n,m;
	cin>>n>>m;
	while(m--){
		int u,v;
		cin>>u>>v;
		Adj[u].push_back(v);
		Adj[v].push_back(u);
	}
	int ans = 0;
	for(int i = 1;i<=n;i++){
		edges=0;
		cnt=0;
		if(vis[i]==0){
			DFS(i);
			edges/=2;
			//cout<<edges<<" "<<cnt<<endl;
		}
		if(edges==cnt-1){
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}