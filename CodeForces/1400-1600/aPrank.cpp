#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a[1010],c=1,m=0;
	cin>>n;
	a[0]=0;
	a[n+1]=1001;
	a[n+2]=1008;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n+2;i++){
		if(a[i]==a[i-1]+1){
			c++;
		}
		else{
			c--;
			m=max(m,c);
			c=1;
		}
	}
	cout<<(max(m,c)-1);
	
}