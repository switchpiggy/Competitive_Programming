#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,i;
	double ans=1.0;
	cin>>n;
	for(i=2;i<=n;i++) ans+=1.0/i;
	printf("%lf",ans);
}