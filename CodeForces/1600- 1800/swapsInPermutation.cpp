#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
const ll INF = 1e18;
const ll mod = 1e9+7;
const ll maxn = 1000 * 1001;
 
ll n , m , k;
 
vector<ll> v[maxn] , mo[maxn];
ll mark[maxn];
 
void dfs(ll u)
{
    for(ll i = 0; i < v[u].size(); i++)
        if(mark[v[u][i]] == 0)
        {
            mark[v[u][i]] = 1;
            mo[k].push_back(v[u][i]);
            dfs(v[u][i]);
        }
}
 
set<pair<ll,ll> > mat;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
 
 
    cin>> n >> m;
 
	ll a[n+1] , b[n+1] , idx[n+1];
 
	for(ll i = 1; i <= n; i++)
    {
        cin>> a[i];
        idx[a[i]] = i;
    }
 
    for(ll i = 1; i <= m; i++)
    {
		ll x , y;
		cin>> x >> y;
        v[a[x]].push_back(a[y]);
        v[a[y]].push_back(a[x]);
	}
 
    for(ll i = 1; i <= n; i++)
        if(mark[i] == 0)
        {
            mark[i] = 1;
            k++;
            mo[k].push_back(i);
            dfs(i);
        }
 
    for(ll i = 1; i <= k; i++)
    {
        ll x[mo[i].size()];
        for(ll j = 0; j < mo[i].size(); j++)
            x[j] = idx[mo[i][j]];
        sort(x , x + mo[i].size());
        sort(mo[i].begin() , mo[i].end());
        reverse(mo[i].begin() , mo[i].end());
        for(ll j = 0; j < mo[i].size(); j++)
            a[x[j]] = mo[i][j];
    }
    for(ll i = 1; i <= n; i++)
        cout<< a[i] <<" ";
}