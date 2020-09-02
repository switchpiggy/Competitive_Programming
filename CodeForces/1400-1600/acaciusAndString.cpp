#include<bits/stdc++.h>
using namespace std;
string sss="abacaba";
string s,ss;
int t,n;
int count(string s){
	int cnt=0;
	int p=s.find(sss);
	while(p>-1&&cnt<2){
		cnt++;
		p=s.find(sss,p+1);
	}
	return cnt;
}
int main(){
	cin>>t;
	while(t--){
		cin>>n>>s;
		bool flag=0;
		for(int i=0;i+7<=n;i++){
			ss=s;
			bool f=1;
			for(int j=0;j<7;j++){
				if(ss[i+j]!='?'&&ss[i+j]!=sss[j]){
					f=0;
					break;
				}
				ss[i+j]=sss[j];
			}
			if(f&&count(ss)==1){
				for(int j=0;j<n;j++){
					if(ss[j]=='?') ss[j]='z';
				}
				flag=1;
				break;
			}
		}
		if(flag) cout<<"Yes"<<endl<<ss<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}