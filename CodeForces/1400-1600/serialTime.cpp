#include<iostream>
#include<cstring>
using namespace std;
int l,h,w,ans;
char a[15][15][15];
bool check(int z,int x,int y){
    if(a[z][x][y]=='#'||z<0||x<0||y<0||z>=l||x>=h||y>=w)return false;
    else return true;
}
void dfs(int z,int x,int y){
    if(check(z,x,y)){
        a[z][x][y]='#';
        ++ans;
        dfs(z,x-1,y);dfs(z,x+1,y);dfs(z,x,y-1);
        dfs(z-1,x,y);dfs(z+1,x,y);dfs(z,x,y+1);
    }
}
int main(){
	cin>>l>>h>>w;
	for(int i=0;i<l;++i)
        for(int j=0;j<h;++j)
            cin>>a[i][j];
    int x,y;
    cin>>x>>y;
    dfs(0,x-1,y-1);
    cout<<ans<<endl;
}