using namespace std;
#include <bits/stdc++.h>
 
#define foreach(i,n) for(__typeof((n).begin())i =(n).begin();i!=(n).end();i++)
#define sgn(x,y) ((x)+eps<(y)?-1:((x)>eps+(y)?1:0))
#define rep(i,n) for(__typeof(n) i=0; i<(n); i++)
#define mem(x,val) memset((x),(val),sizeof(x));
#define rite(x) freopen(x,"w",stdout);
#define read(x) freopen(x,"r",stdin);
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define clr clear()
#define inf (1<<30)
#define ins insert
#define xx first
#define yy second
#define eps 1e-9
 
typedef long long i64;
typedef unsigned long long ui64;
typedef string st;
typedef vector<int> vi;
typedef vector<st> vs;
typedef map<int,int> mii;
typedef map<st,int> msi;
typedef set<int> si;
typedef set<st> ss;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
 
#define mx 200000
#define mod 1000000007ll
 
vi edge[mx];
int _low[mx], _dtime[mx], _dfstime, _stack[mx], _size, _comp[mx], _comps;
bool _instack[mx];
 
void tarjan(int u){
    _low[u]=_dtime[u]=++_dfstime;
    _stack[_size++]=u;
    _instack[u]=true;
 
    rep(i,sz(edge[u])){
        int v=edge[u][i];
        if(_dtime[v]==-1) tarjan(v), _low[u]=min(_low[u],_low[v]);
        else if(_instack[v]) _low[u]=min(_low[u],_dtime[v]);
    }
 
    if(_dtime[u]==_low[u]){
        _comps++;
        int v=-1;
        do{
            v=_stack[--_size];
            _instack[v]=false;
            _comp[v]=_comps;
        }while(u!=v);
    }
}
 
void scc(int n){
    _comps=_dfstime=_size=0;
    mem(_dtime,-1);
    mem(_low,0);
    mem(_stack,0);
    mem(_comp,0);
    mem(_instack,0);
    rep(i,n) if(_dtime[i]==-1)tarjan(i);
}
 
int mini[mx], cnt[mx], cost[mx];
 
int main(){
    int n;
    scanf("%d",&n);
    rep(i,n) {
        scanf("%d",&cost[i]);
        assert(0<=cost[i] && cost[i]<=1000000000);
    }
    int m;
    scanf("%d",&m);
    while(m--){
        int u,v;
        scanf("%d%d",&u,&v);
        assert(1<=u && u<=n);
        assert(1<=v && v<=n);
        u--,v--;
        edge[u].pb(v);
    }
    scc(n);
    for(int i=1; i<=_comps; i++) mini[i]=2000000000;
    rep(i,n){
        int c=_comp[i];
        int w=cost[i];
        if(mini[c]>w) mini[c]=w, cnt[c]=1;
        else if(mini[c]==w) cnt[c]++;
    }
    i64 a=0, b=1;
    for(int i=1; i<=_comps; i++){
        a+=mini[i];
        b*=i64(cnt[i]);
        b%=mod;
    }
    cout<<a<<" "<<b<<endl;
    return 0;
}