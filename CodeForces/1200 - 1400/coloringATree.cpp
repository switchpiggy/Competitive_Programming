#include<cstdio>
using namespace std;
 
const int maxn=1e4+10;
int n,cnt;
int head[maxn],pos,c[maxn];
struct node{int to,next;}e[maxn<<1];
void add(int x,int y){e[++pos].to=y;e[pos].next=head[x];head[x]=pos;}
 
void dfs(int u,int fa)
{
	if(c[u]!=c[fa]) cnt++;
	for(int i=head[u];i;i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa) continue;
		dfs(v,u);
	}
}
 
int main()
{
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	{
		int p;
		scanf("%d",&p);
		add(i,p);
		add(p,i);
	}
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	dfs(1,0);
	printf("%d\n",cnt);
}