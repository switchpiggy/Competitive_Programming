#include<stdio.h>
char c[1000002];int n,cnt=0,v=0;
int main(){
	scanf("%d%s",&n,c+1);
	for(int i=1;i<=n;i++){
		if(c[i]=='(')v++;
		else v--;
		if(v<0||(v==0&&c[i]=='('))cnt++;
	}printf("%d",v?-1:cnt);
}