#include<cstdio>
#include<algorithm> 
#include<cstring>
#include<iostream>
using namespace std;
long long n,i,ans,a[100100];
int main(){
	cin>>n;
	for(i=0;i<n;++i)cin>>a[i]; 
	for(i=1;i<n;++i){
		if(a[i]<a[i-1])ans+=a[i-1]-a[i];
	}
 
	cout<<ans;
	return 0;
}