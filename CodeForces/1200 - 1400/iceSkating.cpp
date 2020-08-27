#include <iostream>
using namespace std;
int n,x[101],y[101],i,ans=-1,ver[101];
void dfs(int a)
{
	ver[a]=1;
	for(int i=1;i<=n;i++)if((x[i]==x[a] || y[i]==y[a]) && !ver[i])dfs(i);
}
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)cin>>x[i]>>y[i];
	for(i=1;i<=n;i++)if(!ver[i])dfs(i),ans++;
	cout<<ans<<endl;
	return 0;
}