#include<stdio.h>
int s[100010];
int main()
{
 
int N;
scanf("%d",&N);
for(int i=1;i<=N; i++)
	scanf("%d",&s[i]);
 
for(int i=1; i<=N; i++)
	if(s[s[s[i]]]==i)
		return puts("YES"), 0;
 
puts("NO");
 
}