#include<bits/stdc++.h>
using namespace std;
 
char s[105][105];
int q[105];
char a[105]; 
 
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int i,j;
	for(i=1;i<=n;i++)
	scanf("%s",s[i]);
	for(i=1;i<=m;i++){
		int k;
		scanf("%d",&k);
		q[k]=true;
	}
	
	int len=0;
	int ans=true;
	for(i=1;i<=n;i++){
		if(q[i]){
			for(j=0;s[i][j];j++)
				if(a[j]&&s[i][j]!=a[j]){
					a[j]='?';
				}
				else
				a[j]=s[i][j];
			if(!len)len=j;
			if(len&&len!=j)ans=false;
		}
	}
	
	for(i=1;ans&&i<=n;i++){
		if(!q[i]){
			bool ok=false;
			for(j=0;s[i][j];j++)
				if(a[j]!='?'&&s[i][j]!=a[j])
					ok=true;
			if(ok==false&&len==j)
				ans=false;
		}
	}
	if(ans)printf("Yes\n%s",a);
	else
	printf("No\n");
	return 0; 
}