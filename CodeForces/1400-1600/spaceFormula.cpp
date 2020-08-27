#include<stdio.h>
#define N 200005
 
int n,m,a[N],b[N],ans;
 
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",a+i);
	for (int i=1;i<=n;i++) scanf("%d",b+i);
	for (int i=1,r=n;i<=n;i++) if (i!=m)
	{
		if (a[i]+b[r]<=a[m]+b[1]) r--;
		else ans++;
	}
	printf("%d\n",ans+1);
}