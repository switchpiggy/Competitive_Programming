#include <bits/stdc++.h>
using namespace std;
 
vector<int> v[1050];
int m[1050];
 
int dfs(int p)
{
	m[p]=1;
	for(int k=0;k<v[p].size();k++)
	{
		if(m[v[p][k]]==0)
		{
			dfs(v[p][k]);
		}
	}
}
 
 
int main() {
int n,w,i,j,flag=0,x,y,c=0;
cin>>n>>w;
memset(m,0,sizeof(m));
for(i=0;i<n;i++)
{
	cin>>x;
	for(j=0;j<x;j++)
	{	flag=1;
		cin>>y;
		y=y-1;
		v[i].push_back(y+n);
		v[y+n].push_back(i);
	}
}
if(flag==0)
cout<<n<<"\n";
else
{
	for(i=0;i<n;i++)
	{
		if(m[i]==0)
		{
			dfs(i);
			c++;
		}
	}
	cout<<c-1<<"\n";
}
 
	return 0;
}