#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
using namespace std;
int n,m,k,par[55][55],ans;
char c[55][55];
vector < pair<int,int> > v;
vector <int> v2;
bool fl[2505];
void dfs (int i,int j){
    v[v.size()-1].f++;
    par[i][j]=v.size()-1;
    if (i==1 || j==1 || i==n || j==m) v[v.size()-1].s=-1;
    if (i!=1 && c[i-1][j]=='.' && par[i-1][j]==-1) dfs(i-1,j);
    if (i!=n && c[i+1][j]=='.' && par[i+1][j]==-1) dfs(i+1,j);
    if (j!=1 && c[i][j-1]=='.' && par[i][j-1]==-1) dfs(i,j-1);
    if (j!=m && c[i][j+1]=='.' && par[i][j+1]==-1) dfs(i,j+1);
    return;
}
int main(){
    cin>>n>>m>>k;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++){
            cin>>c[i][j];
            par[i][j]=-1;
        }
    
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            if (par[i][j]==-1 && c[i][j]=='.') { v.pb(mp(0,v.size())); dfs(i,j); }
 
    sort(v.begin(),v.end());
    for (int i=0; i<v.size(); i++)
        if (v[i].s!=-1) k--;
 
    k*=-1;
    for (int i=0; i<v.size() && k; i++)
        if (v[i].s!=-1) { ans+=v[i].f; fl[v[i].s]=1; k--; }
    
    cout<<ans<<endl;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (par[i][j]!=-1 && fl[par[i][j]]) c[i][j]='*';
            cout<<c[i][j];
        }
        cout<<endl;
    }
                
    return 0;
}