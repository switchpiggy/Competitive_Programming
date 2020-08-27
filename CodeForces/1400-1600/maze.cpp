#include<iostream>
using namespace std;
char maps[505][505];
bool go[505][505];
int cnt,counter;
int n,m,k;
void dfs(int x,int y){
	if(go[x][y])return;
	if(cnt==counter-k)return;
	if(x==n||y==m)return;
	if(x<0||y<0)return;
	if(maps[x][y]=='#')return;
	cnt++;
	go[x][y]=1;
	maps[x][y]='.';
	dfs(x+1,y);
	dfs(x,y+1);
	dfs(x-1,y);
	dfs(x,y-1);
}
int s,e;
int main(){
	cin>>n>>m>>k;
	for(int i=0;i<n;i++){
		cin>>maps[i];
		for(int u=0;u<m;u++)if(maps[i][u]=='.')maps[i][u]='X',s=i,e=u,counter++;
	}
	dfs(s,e);
	for(int i=0;i<n;i++){
		cout<<maps[i]<<endl;
	}
}