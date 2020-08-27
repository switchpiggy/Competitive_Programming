#include<bits/stdc++.h>
using namespace std;
vector <int> enemy[105];
int m,n;
int ans,cnt,cnt2;
bool used[105];
 
void dfs(int a){
	used[a]=true;
	cnt+=enemy[a].size();
	cnt2++;
	for(int i=0;i<enemy[a].size();i++)
		if(!used[enemy[a][i]])
			dfs(enemy[a][i]);
}
 
int main(){
	cin>>m>>n;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		enemy[a].push_back(b);
		enemy[b].push_back(a);
	}
	for(int i=1;i<=m;i++){
		if(!used[i]){
		cnt=0;
		cnt2=0; 
		dfs(i);
		if(cnt2%2==1 && cnt2*2==cnt)
			ans++;
		}
	}
	if((m-ans)%2)	ans++;
	cout<<ans;
	return 0;
}