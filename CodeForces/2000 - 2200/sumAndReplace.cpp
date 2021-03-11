#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAX=1e6,N=3e5;
ll d[MAX+5],arr[N+5],jum[4*N+5],maxx[4*N+5],n,m;
void f(ll id,ll l,ll r)
{
	if(l==r)
	{
		jum[id]=arr[l];
		maxx[id]=arr[l];
		return;
	}
	ll mid=(l+r)/2;
	f(2*id,l,mid);
	f(2*id+1,mid+1,r);
	jum[id]=jum[2*id]+jum[2*id+1];
	maxx[id]=max(maxx[2*id],maxx[2*id+1]);
}
void upd(ll id,ll l,ll r,ll x,ll y)
{
	if(maxx[id]<=2) return;
	if(l==r)
	{
		ll now=jum[id];
		jum[id]=d[now];
		maxx[id]=d[now];
		return;
	}
	ll mid=(l+r)/2;
	if(x<=mid) upd(2*id,l,mid,x,y);
	if(mid<y) upd(2*id+1,mid+1,r,x,y);
	jum[id]=jum[2*id]+jum[2*id+1];
	maxx[id]=max(maxx[2*id],maxx[2*id+1]);
}
ll q(ll id,ll l,ll r,ll x,ll y)
{
	if(l>=x&&y>=r) return jum[id];
	ll mid=(l+r)/2,has=0;
	if(x<=mid) has+=q(2*id,l,mid,x,y);
	if(mid<y) has+=q(2*id+1,mid+1,r,x,y);
	return has;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for(int i=1;i<=MAX;i++)
	{
		for(int j=i;j<=MAX;j+=i) d[j]++;
	}
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>arr[i];
	f(1,1,n);
	for(int i=1;i<=m;i++)
	{
		ll a,b,c;
		cin>>a>>b>>c;
		if(a==1) upd(1,1,n,b,c);
		else cout<<q(1,1,n,b,c)<<endl;
	}
}