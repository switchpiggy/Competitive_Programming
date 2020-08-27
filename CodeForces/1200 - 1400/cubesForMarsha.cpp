#include<bits/stdc++.h>
 
using namespace std;
 
int n;
int a[5][10];
bool vis[100];
 
int main(){
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) for(int j=1; j<=6; ++j) scanf("%d", &a[i][j]);
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=6; ++j){
			vis[a[i][j]] = true;
			for(int k=1; k<=n; ++k) if(k!=i){
				for(int k2=1; k2<=6; ++k2) vis[a[i][j]*10+a[k][k2]]=true;
			}
		}
	}
	int i;
	for(i=1; i<=99; ++i) if(!vis[i]) break;
	printf("%d\n", i-1);
}