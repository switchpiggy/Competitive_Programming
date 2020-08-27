#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,a[N],Min;
vector<int> e[N];
bool vis[N];
void dfs(int x){
	if (vis[x]) return;
	vis[x]=1;
	Min=min(Min,a[x]);
	for (auto v:e[x]) dfs(v);
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	long long ans=0;
	for (int i=1;i<=n;i++)
	if (!vis[i]){
		Min=1e9;
		dfs(i);
		ans+=Min;
	}
	cout<<ans<<endl;
	return 0;
}