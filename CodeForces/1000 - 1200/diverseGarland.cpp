#include<cstdio>
#include<cstring>
 
char s[200005];
int main()
{
	int n,ans=0;
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=2;i<=n;i++)
	{
		if(s[i]==s[i-1])
		{
			if(s[i]=='R') s[i]='B'+('G'-'B')*(s[i+1]=='B');
			else if(s[i]=='G') s[i]='B'+('R'-'B')*(s[i+1]=='B');
			else s[i]='G'+('R'-'G')*(s[i+1]=='G');
			ans++;
		}
	}
	printf("%d\n%s",ans,s+1);
}